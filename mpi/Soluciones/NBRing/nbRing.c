  GNU nano 2.3.1                                                         File: nbRing.c                                                                                                                         

#include <stdio.h>
#include <mpi.h>

#define MAX 100000

int main(int argc, char **argv)
{
        int rank, size, tag=99;
        int i, array[MAX], left[MAX];
        MPI_Status stats[2];
        MPI_Request reqs[2];

        for(i=0; i<MAX; i++)
        {
                array[i] = rank*MAX + i;
        }

	MPI_Init(&argc, &argv);
        MPI_Comm_rank(MPI_COMM_WORLD, &rank);
        MPI_Comm_size(MPI_COMM_WORLD, &size);


        MPI_Irecv(&left, MAX, MPI_INTEGER, (rank+size-1)%size, tag,MPI_COMM_WORLD, &reqs[0]);
        MPI_Isend(&array, MAX, MPI_INTEGER, (rank+1)%size, tag, MPI_COMM_WORLD, &reqs[1]);

        MPI_Waitall(2,reqs,stats);

        printf("I am MPI process %d, received data from: %d, sent data to: %d\n", rank,(rank+size-1)%size,(rank+1)%size);

        MPI_Finalize();

        return 0;
}



