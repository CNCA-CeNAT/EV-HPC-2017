/**
 * University of Pittsburgh
 * Department of Computer Science
 * CS1645: Introduction to HPC Systems
 * Instructor Esteban Meneses (emeneses@pitt.edu)
 * MPI collective computation program.
 */
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FLAG 7

// Main routine
int main (int argc, char *argv[]){
	int rank, size, number, counter;

	// initialize MPI
	MPI_Init(&argc, &argv);	
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);	
	MPI_Comm_size(MPI_COMM_WORLD, &size);	

	// computing sum of all numbers in the system
	srand(time(NULL));
	number = rand() % size;
	MPI_Allreduce(&number, &counter, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);

	printf("[%d] Total sum: %d\n", rank, counter);

	// finalize MPI
	MPI_Finalize();
	return 0;
}
