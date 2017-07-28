#include <stdio.h>
#include "mpi.h"

int main(int argc, char *argv[]){

        int i, sum, sumTotal, upToVal;
        int start, end, size, myRank;


        upToVal = 10000;

        MPI_Init(&argc, &argv);
        MPI_Comm_size(MPI_COMM_WORLD, &size);
        MPI_Comm_rank(MPI_COMM_WORLD, &myRank);

        start = myRank*(upToVal/size)+1;

        if(myRank == (size-1)){
                end = upToVal;
        }else{
                end = start + (upToVal/size)-1;
        }

	sum = 0;
        sumTotal = 0;

        for(i=start; i <= end; i++){
                sum = sum +i;
        }

	MPI_Reduce(&sum, &sumTotal, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

        printf("\nRank: %d, local sum: %d, total sum: %d\n", myRank, sum, sumTotal);

        MPI_Finalize();

        return 0;

}









