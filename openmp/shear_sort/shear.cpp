/**
 * Advanced Computing Laboratory
 * Costa Rica National High Technology Center
 * Esteban Meneses, PhD (emeneses@cenat.ac.cr)
 * OpenMP parallel shear sort.
 */

#include <cstdlib>
#include <iostream>
#include <math.h>

using namespace std;

void sort_row(int **A, int M, int i, int order);
void sort_col(int **A, int M, int j);

// Shear Sort function
void shear_sort(int **A, int M){
	int N = M*M, total;
	total = ceil(log2(N));

	for(int stage=0; stage<total; stage++){

		// sorting rows
		for(int i=0; i<M; i++){
			sort_row(A,M,i,int(pow(-1,i)));
		}

		// sorting columns
		for(int j=0; j<M; j++){
			sort_col(A,M,j);
		}
	}
}

// Function to sort row (uses bubble sort)
void sort_row(int **A, int M, int i, int order){
	for(int step=0; step<M; step++) {
		for(int j=1; j<M; j++){
			if(A[i][j-1]*order > A[i][j]*order) {
				int tmp = A[i][j-1];
				A[i][j-1] = A[i][j];
				A[i][j] = tmp;
			}
		}
	}
}

// Function to sort column (uses bubble sort)
void sort_col(int **A, int M, int j){
	for(int step=0; step<M; step++) {
		for(int i=1; i<M; i++){
			if(A[i-1][j] > A[i][j]) {
				int tmp = A[i-1][j];
				A[i-1][j] = A[i][j];
				A[i][j] = tmp;
			}
		}
	}
}

