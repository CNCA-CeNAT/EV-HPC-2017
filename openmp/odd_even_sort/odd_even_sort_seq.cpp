/**
 * Advanced Computing Laboratory
 * Costa Rica National High Technology Center
 * Esteban Meneses, PhD (emeneses@cenat.ac.cr)
 * OpenMP parallel odd-even sort.
 */

#include <cstdio>
#include <cstdlib>
#include <omp.h>
#include "timer.h"
#include "io.h"
#define MAX_VALUE 10000

// Main method      
int main(int argc, char* argv[]) {
	int N;
	int *A;
	double elapsedTime;

	// checking parameters
	if (argc != 2 && argc != 3) {
		cout << "Parameters: <N> [<file>]" << endl;
		return 1;
	}
	N = atoi(argv[1]);

	// allocating array
	A = new int[N];

	// reading files (optional)
	if(argc == 3){
		readArrayFile(A,N,argv[2]);
	} else {
		srand48(time(NULL));
		for(int i=0; i<N; i++){
			A[i] = lrand48() % MAX_VALUE;
		}
	}

	// starting timer
	timerStart();

	// odd-even sort
	for(int i=0; i<N; ++i) {
		if(i & 1) {
			for(int j=2; j<N; j+=2)
				if(A[j] < A[j-1])
					swap(A[j-1], A[j]);
		} else {
			for(int j=1; j<N; j+=2)
				if(A[j] < A[j-1])
					swap(A[j-1], A[j]);
		}
	}

	// testing the results is correct
	if(argc == 3){
		printArray(A,N);
	}
	
	// stopping timer
	elapsedTime = timerStop();

	cout << "Duration: " << elapsedTime << " seconds" << std::endl;

	// releasing memory
	delete [] A;

	return 0;	
}

