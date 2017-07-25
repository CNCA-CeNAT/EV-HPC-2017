#include <stdlib.h>
#include <stdio.h>

void ES_teclado_1()
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

void ES_teclado_2()
{
    char str[100];

    printf( "Enter a value: ");
    fgets( str, 100, stdin );
    printf( "\n");
    printf( "You entered: ");
    fputs( str, stdout );
    printf( "\n");

    return;
}

void ES_teclado_3()
{
    char str[100];
    int val;
    float r;
    
    
    printf( "Enter a value: ");
    fscanf(stdin, "%s %d %f", str, &val, &r);
    printf( "\n");
    printf( "You entered: ");
    printf( "%s, %d, %f ", str, val, r);
    printf( "\n");

    return;
}


void ES_archivo()
{
    FILE* f_ptr = fopen("text", "a+");
    if(f_ptr != 0x0)
    {
        char *linea = NULL;
        int num_linea = 1;
        int largo = 0;
        int r;
        
        int fin = 0;
        while(!fin)
        {
            r = getline(&linea, &largo, f_ptr);
            
            //printf("==%d\n",r);

            if(r != -1)
            {
                printf("%d: %s", num_linea, linea);
                num_linea++;
            }
            else
            {
                printf("fin de archivo\n");
                fin = 1;
            }
        }
        
        free(linea);
        
        
        
        fprintf(f_ptr, "NOOOOOOoooooooOOOOOooooo!\n");
        fprintf(f_ptr, "NOOOOOOoooooooOOOOOooooo!\n");
        fprintf(f_ptr, "NOOOOOOoooooooOOOOOooooo!\n");
        
        
        fclose(f_ptr);
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
