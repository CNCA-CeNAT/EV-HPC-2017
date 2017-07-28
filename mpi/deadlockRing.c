#include <stdio.h>
#include <mpi.h>

#define MAX 100000

int main(int argc, char **argv)
{
	int rank, size, tag=99;
	int i, array[MAX], left[MAX];
	MPI_Status status;

	for(i=0; i<MAX; i++)
	{
		array[i] = rank*MAX + i;
	}

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	
	MPI_Send(&array, MAX, MPI_INTEGER, (rank+1)%size, tag, MPI_COMM_WORLD);
	MPI_Recv(&left, MAX, MPI_INTEGER, (rank+size-1)%size, tag,MPI_COMM_WORLD, &status);
	
	printf("%d received array\n", rank);
	
	MPI_Finalize();
	
	return 0;
}
