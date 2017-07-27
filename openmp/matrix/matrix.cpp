/**
 * Advanced Computing Laboratory
 * Costa Rica National High Technology Center
 * Esteban Meneses, PhD (emeneses@cenat.ac.cr)
 * OpenMP parallel matrix multiplication.
 */

#include <omp.h>
#include <time.h>
#include <iostream>
#include <math.h>
#include "timer.h"
#include "io.h"

using namespace std;

// Main routine
int main (int argc, char *argv[]){
	int N;
	double *A, *B, *C;
	double duration;

	if(argc > 1){
		N = atoi(argv[1]);
	} else {
		cout << "Usage: " << argv[0] << " <N>" << endl;
		exit(1);
	}

	// declaring matrices for matrix multiplication
	posix_memalign((void**)&A, 64, N*N*sizeof(double));
	posix_memalign((void**)&B, 64, N*N*sizeof(double));
	posix_memalign((void**)&C, 64, N*N*sizeof(double));

	// starts timer
	timerStart();

	#pragma omp parallel for
	for(int i=0; i<N; i++){
		for(int k=0; k<N; k++){
			for(int j=0; j<N; j++){
				C[i*N+j] += A[i*N+k]*B[k*N+j];
			}
		}
	}
	
	// stops timer
	duration = timerStop();

	// printing output
	cout << "Execution time: " << duration << " seconds" << endl;

}
