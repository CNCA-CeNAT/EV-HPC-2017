#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv)
{
    /* local variable definition */
    int a = 100;
    int b = 200;

    /* check the boolean condition */
    if( a == 100 ) {

        /* if condition is true then check the following */
        if( b == 200 ) {
        /* if condition is true then print the following */
            printf("Value of a is 100 and b is 200\n" );
        }
    }

    printf("Exact value of a is : %d\n", a );
    printf("Exact value of b is : %d\n", b );





    /* local variable definition */
    char grade = 'B';

    switch(grade) {
        case 'A' :
            printf("Excellent!\n" );
            break;
        case 'B' :
        case 'C' :
            printf("Well done\n" );
            break;
        case 'D' :
            printf("You passed\n" );
            break;
        case 'F' :
            printf("Better try again\n" );
            break;
        default :
            printf("Invalid grade\n" );
    }

    printf("Your grade is  %c\n", grade );



    a = 0;
    /* while loop execution */
    while( a < 20 ) {
        printf("in a while loop, value of a: %d\n", a);
        a++;
    }




    printf("\n\n");




    for( a = 10; a < 20; a = a + 1 ){
        printf("in a for loop, value of a: %d\n", a);
    }






    return 0;
}
