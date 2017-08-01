#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <mpi.h>

#include "mkl.h"

#define SIZE 10000

double seconds(){

    struct timeval tmp;
    double sec;
    gettimeofday( &tmp, (struct timezone *)0 );
    sec = tmp.tv_sec + ((double)tmp.tv_usec)/1000000.0;
    return sec;
}

int main( int argc, char *argv[] ){

  int rank, nprocs;

  int i = 0, j = 0, k = 0, j_global = 0, size_loc = 0, count = 0;
  size_t size_in_bytes;
  size_t block_size_in_bytes;

  double *A, *B, *C, *C_block, *B_block, *B_buff;
  double t_start, t_mine, t_slowest;

#ifdef __DEBUG
  double *A_Global, *B_Global, *C_Global, *C_Parallel;
#endif

  MPI_Init( &argc, &argv );
  MPI_Comm_rank( MPI_COMM_WORLD, &rank );
  MPI_Comm_size( MPI_COMM_WORLD, &nprocs );
  
  size_loc = SIZE / nprocs ;

  size_in_bytes = size_loc * SIZE * sizeof(double);
  block_size_in_bytes = size_loc * size_loc * sizeof(double);

  A = (double *) malloc( size_in_bytes );
  B = (double *) malloc( size_in_bytes );
  B_block = (double *) malloc( block_size_in_bytes );
  B_buff = (double *) malloc( size_in_bytes );
  C = (double *) malloc( size_in_bytes );

  // Initialization of matrices A and B to random values 
  for( i = 0; i < size_loc*SIZE; i++ ){

    A[i] = (double) rand();
    B[i] = (double) rand();
    
  }
  memset( C, 0, size_in_bytes );

  t_start = seconds();
  for( count = 0; count < nprocs; count++ ){
    
    // prepare the block
    for( i = 0; i < size_loc; i++)
      for( j = 0; j < size_loc; j++){
	j_global = j + ( size_loc * count );
	B_block[ ( i * size_loc ) + j ] = B[ ( i * SIZE ) + j_global ];
      }
    
    MPI_Allgather( B_block, size_loc * size_loc, MPI_DOUBLE, B_buff, size_loc * size_loc, MPI_DOUBLE, MPI_COMM_WORLD );
    
    C_block = C + ( size_loc * count );
    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, size_loc, size_loc, SIZE, 1.0, A, SIZE, B_buff, size_loc, 0.0, C_block, SIZE);
         
  } 
  t_mine = seconds() - t_start;

  MPI_Reduce( &t_mine, &t_slowest, 1, MPI_DOUBLE, MPI_MAX, 0, MPI_COMM_WORLD );

#ifdef __DEBUG
      
  if( !rank){
    A_Global = (double *) malloc( SIZE * SIZE * sizeof(double) );
    B_Global = (double *) malloc( SIZE * SIZE * sizeof(double) );
    C_Global = (double *) malloc( SIZE * SIZE * sizeof(double) );
    C_Parallel = (double *) malloc( SIZE * SIZE * sizeof(double) );
  }  

  MPI_Gather( A, SIZE * size_loc, MPI_DOUBLE, A_Global, SIZE * size_loc, MPI_DOUBLE, 0, MPI_COMM_WORLD);
  MPI_Gather( B, SIZE * size_loc, MPI_DOUBLE, B_Global, SIZE * size_loc, MPI_DOUBLE, 0, MPI_COMM_WORLD);
  MPI_Gather( C, SIZE * size_loc, MPI_DOUBLE, C_Parallel, SIZE * size_loc, MPI_DOUBLE, 0, MPI_COMM_WORLD);

  if( !rank ){    

    memset( C_Global, 0, size_in_bytes );  
  
    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, SIZE, SIZE, SIZE, 1.0, A_Global, SIZE, B_Global, SIZE, 0.0, C_Global, SIZE);

    for( i = 0; i < size_loc; i++){
      for( j = 0; j < size_loc; j++){
	  
	count = ( i * SIZE ) + j;
	  
	if( C_Global[count] != C_Parallel[count] ){
	    
	  fprintf( stderr, "\n\tProgramm Error! C_Parallel[%d][%d] != C_Global[%d][%d] => %.3g != %.3g ...\n\n", i, j, i, j, C_Parallel[count], C_Global[count] );
	  MPI_Abort( MPI_COMM_WORLD, 1 );
	}
      }
    }
      
    free ( A_Global );
    free ( B_Global );
    free ( C_Global );
    free ( C_Parallel );

  }
#endif
  
  if( !rank ){
    fprintf( stdout, "\n\tParallel DGEMM Completed Succesfully! \n" );
    fprintf( stdout, "\tTime to solution of %.3g seconds for SIZE = %d \n\n", t_slowest, SIZE );
  }
  
  free( A );
  free( B );
  free( C );
  free( B_block );
  free( B_buff );
  
  MPI_Finalize();
  
  return 0;
}
  
