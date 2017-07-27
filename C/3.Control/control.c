/*
Escuela de veranillo en computacion de alto rendimiento.
24-28 julio 2017
CNCA, CeNAT.

M. Sc. Ricardo Roman-Brenes, PRIS-Lab/EIE/UCR
ricardo.roman@ucr.ac.cr
*/

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv)
{
    
    // bifurcacion o condicional (IF/ELSE)
    
    int a = 100;
    int b = 200;

    // verificacion de condicion
    if( a == 100 ) {

        // pueden estar anidadas
        if( b >= 200 ) // caso verdadero
        { 
            printf("a es 100 y b es igual o mayor que 200\n" );
        }
        else // caso falso
        {
            printf("a es 100 y b es menor que 200\n" );
        }
    }


    printf("\n\n");


    // switch

    char grade = 'B';

    switch(grade) {
        case 'A' :
            printf("excelente!\n" );
            break;
        case 'B' :
            printf("muy bien!\n" );
            break;
        case 'C' :
            printf("aceptable.\n" );
            break;
        case 'D' :
            printf("tolerable.\n" );
            break;
        case 'F' :
            printf("reprobado.\n" );
            break;
        default :
            printf("nota invalida! error.\n" );
            break;
    }

    printf("su nota es %c\n", grade );


    printf("\n\n");



    // ciclo mientras (WHILE)
    
    int fin = 0;
    int v = 0;
    
    while( !fin ) // mientras la condicion se cumpla se ejecuta
    {
        printf("en el ciclo, v: %d\n", v);
        v++;
        if(v > 20) // para terminar el ciclo, se debe cambiar el valor de FIN
        {
            fin = 1;
        }
    }


    printf("\n\n");


    // ciclo para (FOR)
    int i;
    for( i = 0; i < 20; i++ ){
        printf("en el ciclo, i: %d\n", i);
    }


    return 0;
}
