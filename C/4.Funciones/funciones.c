/*
Archivo de fuentes.
Se ponen aca las implementaciones o asignaciones (variables o funciones)
*/

#include "funciones.h" // se incluye el respectivo archivo de encabezado


void f(int x)
{
    int a = x + 10;
    printf("%d\n", a);
    return;
}


float g(float x, float y)
{
    float a = x * y;
    return a;
}


char* h(int x, float y, char z)
{
    char* a = (char*)malloc(sizeof(char)*x+1); // asignacion de memoria
    int i;
    
    for(i=0; i < x; i++)
    {
        y+=y;
        printf("%f\n", y);
        a[i] = z;
    }
    a[i] = '\0';
    return a;
}
