/**
 * Advanced Computing Laboratory
 * Costa Rica National High Technology Center
 * Esteban Meneses, PhD (emeneses@cenat.ac.cr)
 * OpenMP parallel hello world.
 */

#include <omp.h>
int main(){
	#pragma omp parallel
	printf("Hello World\n");
}
