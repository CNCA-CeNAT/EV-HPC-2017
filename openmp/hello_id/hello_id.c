/**
 * Advanced Computing Laboratory
 * Costa Rica National High Technology Center
 * Esteban Meneses, PhD (emeneses@cenat.ac.cr)
 * OpenMP parallel hello world.
 */

#include <omp.h>
int main(){
	int id, np;
	#pragma omp parallel private(id, np) 
	{
		np = omp_get_num_threads();
		id = omp_get_thread_num();
		printf("Hello from thread %d, out of %d threads\n",id,np);
	}
}
