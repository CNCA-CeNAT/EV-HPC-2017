/*
Escuela de veranillo en computacion de alto rendimiento.
24-28 julio 2017
CNCA, CeNAT.

M. Sc. Ricardo Roman-Brenes, PRIS-Lab/EIE/UCR
ricardo.roman@ucr.ac.cr
*/

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

    // el orden de los operadores importa!! Igual que en matematica
    
    e = (a + b) * c / d;      // ( 30 * 15 ) / 5
    printf("(a + b) * c / d = %d\n",  e );

    e = ((a + b) * c) / d;    // (30 * 15 ) / 5
    printf("((a + b) * c) / d = %d\n" ,  e );

    e = (a + b) * (c / d);   // (30) * (15/5)
    printf("(a + b) * (c / d) = %d\n",  e );

    e = a + (b * c) / d;     //  20 + (150/5)
    printf("a + (b * c) / d = %d\n" ,  e );



    printf("\n\n");


    f(27);

    printf("\n\n");

    float x = g(1.9, 6.6);
    printf("%f\n", x);

    printf("\n\n");
    char* y= h(4, 2.5, '$');
    printf("%s\n", y);
    free(y);
    
    
    return 0;
}
