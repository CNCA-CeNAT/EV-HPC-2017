#include <stdlib.h>
#include <stdio.h>



float* f()
{
    float a[2];
    a[0] = 1.0;
    a[1] = 1.1;
    return a;
}

float* g()
{
    float* a=(float*)malloc(2*sizeof(float));
    a[0] = 1.0;
    a[1] = 1.1;
    return a;
}

void h(int* salida)
{
    //calculo
    //...
    
    *salida = 123;
    return;
}

int main(int argc, char** argv)
{

    //float* a = f(); // ojo! error.
    //printf("%p\n", a);
    //free(a);
    
    float* b = g();
    printf("%p\n", b);
    free(b);
    
    
    int* arreglo; // ojo! solo esta declarado el puntero.
    arreglo = (int*)malloc(4000*sizeof(int));

    printf("%p\n", arreglo);
    arreglo[4000] = 3;
    free(arreglo);
    
    
    int* salida;
    salida = (int*)malloc(1*sizeof(int));
    h(salida);
    printf("%d\n", *salida);


    return 0;
}
