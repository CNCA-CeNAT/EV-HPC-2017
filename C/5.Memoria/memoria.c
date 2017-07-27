/*
Escuela de veranillo en computacion de alto rendimiento.
24-28 julio 2017
CNCA, CeNAT.

M. Sc. Ricardo Roman-Brenes, PRIS-Lab/EIE/UCR
ricardo.roman@ucr.ac.cr
*/

#include <stdlib.h>
#include <stdio.h>



float* f() // funcion mala.
{
    float a[2]; // variable en pila, es temporal.
    a[0] = 1.0;
    a[1] = 1.1;
    return a; // al retornar la direccion de la variable local o temporal puede crear inestabilidad (de fijo lo hace).
}

float* g()
{
    float* a=(float*)malloc(2*sizeof(float)); // variable en heap, permanece hasta que se borre.
    a[0] = 1.0;
    a[1] = 1.1;
    return a; // se retorna la direccion de la variable en heap.
}

void h(int* salida)
{
    //calculo
    //...
    
    *salida = 123; // desreferenciacion de puntero. Da el valor de lo que esta siendo apuntado por salida.
    return;
}

double* i()
{
    double* d = (double*)malloc(sizeof(double));
    *d = 123.512;
    printf("direccion de d en la funcion i: %p. valor de d %lf\n", d, *d);
    return d;
}
    

int main(int argc, char** argv)
{
    // ojo! error.
    //float* a = f(); 
    //printf("%p\n", a);
    //free(a);
    
    float* b = g();
    printf("%p\n", b);
    free(b);
    
    
    int* arreglo; // ojo! solo esta declarado el puntero.
    arreglo = (int*)malloc(4000*sizeof(int)); // aqui se le da memoria. si se usa antes de pedirle memoria, puede ocurrir fallo de segmento.

    printf("%p\n", arreglo);
    arreglo[4000] = 3;
    free(arreglo);
    
    
    int* salida;
    salida = (int*)malloc(1*sizeof(int));
    h(salida);
    printf("%d\n", *salida);

    
    double* d = i();
    printf("direccion de d fuera de la funcion i: %p. valor de d %lf\n", d, *d);
    
    
    return 0;
}
