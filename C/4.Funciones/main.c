#include <stdlib.h>
#include <stdio.h>
#include "funciones.h"

int main(int argc, char** argv)
{
    
    
    int a = 20;
    int b = 10;
    int c = 15;
    int d = 5;
    int e;

    e = (a + b) * c / d;      // ( 30 * 15 ) / 5
    printf("Value of (a + b) * c / d is : %d\n",  e );

    e = ((a + b) * c) / d;    // (30 * 15 ) / 5
    printf("Value of ((a + b) * c) / d is  : %d\n" ,  e );

    e = (a + b) * (c / d);   // (30) * (15/5)
    printf("Value of (a + b) * (c / d) is  : %d\n",  e );

    e = a + (b * c) / d;     //  20 + (150/5)
    printf("Value of a + (b * c) / d is  : %d\n" ,  e );


    
    f(27);

    float x = g(1.9, 6.6);
    printf("%f\n", x);
    
    char* y= h(4, 2.5, '$');
    printf("%s\n", y);
    free(y);
    
    return 0;
}
