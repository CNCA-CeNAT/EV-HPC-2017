/**
 * Advanced Computing Laboratory
 * Costa Rica National High Technology Center
 * Esteban Meneses, PhD (emeneses@cenat.ac.cr)
 * OpenMP parallel Strassen's algorithm.
 */

#include <cstdio>
#include <cstdlib>
#include <omp.h>
#include "timer.h"
#include "io.h"

// Main method      
int main(int argc, char* argv[]) {
	int N;
	int **A, **B, **C;
	double elapsedTime;

	// checking parameters
	if (argc != 2 && argc != 4) {
		cout << "Parameters: <N> [<fileA> <fileB>]" << endl;
		return 1;
	}
	N = atoi(argv[1]);

	// allocating matrices
	A = new int*[N];
	B = new int*[N];
	C = new int*[N];
	for (int i=0; i<N; i++){
		A[i] = new int[N];
		B[i] = new int[N];
		C[i] = new int[N];
	}

	// reading files (optional)
	if(argc == 4){
		readMatrixFile(A,N,argv[2]);
		readMatrixFile(B,N,argv[3]);
	}

	// starting timer
	timerStart();

	// YOUR CODE GOES HERE

	// testing the results is correct
	if(argc == 4){
		printMatrix(C,N);
	}
	
	// stopping timer
	elapsedTime = timerStop();

	cout << "Duration: " << elapsedTime << " seconds" << std::endl;

	// releasing memory
	for (int i=0; i<N; i++) {
		delete [] A[i];
		delete [] B[i];
		delete [] C[i];
	}
	delete [] A;
	delete [] B;
	delete [] C;

	return 0;	
}

