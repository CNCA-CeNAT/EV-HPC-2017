#include <stdio.h>

int main(int argc, char *argv[]){

        int i, sum, upToVal;
        upToVal = 10000;
        sum = 0;


        for(i=1; i <= upToVal; i++){
                sum = sum +i;
        }

	printf("\nSum is %d\n", sum);

        return 0;

}
