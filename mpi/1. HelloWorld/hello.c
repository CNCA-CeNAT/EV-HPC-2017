#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

// Main routine
int main (int argc, char *argv[]){
    int rank,size,length;
    char name[25];

    // initialize MPI
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Get_processor_name(name, &length);
    printf( "Hello world from rank %d of %d on host %s\n", rank, size, name);

    // finalize MPI
    MPI_Finalize();
    return 0;
}





