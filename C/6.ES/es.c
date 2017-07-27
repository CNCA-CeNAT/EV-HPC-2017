/*
Escuela de veranillo en computacion de alto rendimiento.
24-28 julio 2017
CNCA, CeNAT.

M. Sc. Ricardo Roman-Brenes, PRIS-Lab/EIE/UCR
ricardo.roman@ucr.ac.cr
*/

/*
Descomentar llamados a funciones en main para probarlas.
*/


#include <stdlib.h>
#include <stdio.h>

void ES_teclado_1() // entrada-salida del teclado a la pantalla usando funciones getchar y putchar
{
    char c;

    printf( "Enter a value: ");
    c = getchar( );
    printf( "\n");
    printf( "You entered: ");
    putchar( c );
    printf( "\n");

    return;
}

void ES_teclado_2() // entrada-salida del teclado a la pantalla usando funciones fgets y fputs
{
    char str[100];

    printf( "Enter a value: ");
    fgets( str, 100, stdin ); // los argumentos son, un puntero a donde se van a guardar los caracteres digitados, el largo de ese puntero, y de donde entran los datos STDIN es el teclado.
    printf( "\n");
    printf( "You entered: ");
    fputs( str, stdout ); // los argumentos son, el puntero, y a donde se imprimiran los datos, STDOUT es la pantalla.
    printf( "\n");

    return;
}

void ES_teclado_3() // entrada-salida del teclado a la pantalla usando funciones fscanf y printf. Utiles cuando se debe leer o escribir en algun formato particular.
{
    char str[100];
    int val;
    float r;
    
    
    printf( "Enter a value: ");
    
    /*
    Los argumentos son: la entrada, la forma en la que se espera la entrada (en un char*), una lista de punteros de donde se guardaran las entradas esperadas.
    En este caso hay, un texto (%s), un numero entero (%d) y un numero decimal (%f), que se guardan en las direccinones de str, val y r.
    */
    fscanf(stdin, "%s %d %f", str, &val, &r); 
    printf( "\n");
    printf( "You entered: ");
    printf( "%s, %d, %f ", str, val, r);
    printf( "\n");

    return;
}


void ES_archivo() // entrada/salida en archivos.
{
    FILE* f_ptr = fopen("text", "a+"); //apertura de archivo llamado "text" en modo "a+" (tarea, revisar los modos).
    if(f_ptr != 0x0) // verificacion de apertura correcta.
    {
        char *linea = NULL;
        int num_linea = 1;
        size_t  largo = 0; //size_t es un nombre diferente para entero.
        ssize_t r; //ssize_t es un nombre diferente para entero, se usa para medir caracteres.
        
        int fin = 0;
        while(!fin)
        {
            r = getline(&linea, &largo, f_ptr); //leer una linea y guardar el contenido en la variable linea; se guarda la cantidad de caracteres leidos en largo.
            if(r != -1) // r indica si el archivo se acabo o no.
            {
                printf("%d (%d): %s", num_linea, largo, linea); //impresiond e la linea leida
                num_linea++;
            }
            else
            {
                printf("fin de archivo\n");
                fin = 1;
            }
        }
        
        free(linea);
        
        
        
        fprintf(f_ptr, "NOOOOOOoooooooOOOOOooooo!\n"); // similar a printf, solo que se especifica donde se escribe, en esta caso en un archivo. se escribe al final.
        fprintf(f_ptr, "NOOOOOOoooooooOOOOOooooo!\n");
        fprintf(f_ptr, "NOOOOOOoooooooOOOOOooooo!\n");
        
        
        fclose(f_ptr); //cierre de archivo. MUY IMPORTANTE, tanto como los free de los mallocs.
    } 
    else // ocurrio algun error
    {
        printf("Error al leer archivo\n");
    }
    return;
}


int main(int argc, char** argv)
{
    
    //ES_teclado_1();
    //ES_teclado_2();
    //ES_teclado_3();
    
    ES_archivo();
    
    return 0;
}
