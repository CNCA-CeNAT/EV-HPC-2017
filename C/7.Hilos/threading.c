/*
Escuela de veranillo en computacion de alto rendimiento.
24-28 julio 2017
CNCA, CeNAT.

M. Sc. Ricardo Roman-Brenes, PRIS-Lab/EIE/UCR
ricardo.roman@ucr.ac.cr
*/

/*
recordar que se compila con la biblioteca pthread: 
gcc threading.c -pthread

*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

char* sistema = "solar"; // los hilos comparten memoria, todos pueden leer esto. si alguno lo cambia, cambia para todos.

void* imprimir_mensaje(void* mensaje)
{
    char* m;
    m = (char *) mensaje; // convertir mensaje a char*, la funcion para el hilo necesita recibir un void*, pero para imprimir necesitamos un char*.
    int i;

    for(i=0;i<200000;i++)
    {
        printf("Saludos terricolas desde %s en el sistema %s (proceso: %d)\n", m, sistema, getpid()); //siempre es el mismo numero de proceso
    }
    
    return 0x0;
}

int main(int argc, char** argv)
{
    pthread_t h1, h2, h3, h4;
    const char *planeta1 = "Saturno";
    const char *planeta2 = "Marte";
    const char *planeta3 = "Jupiter";
    const char *planeta4 = "Neptuno";
    int  iret1, iret2, iret3, iret4;

    /* Se crean hilos (que corren inmediatamente) */

    // los agumentos son, un puntero al hilo, atributos especiales al hilo (ninguno), un puntero a la funcion que va a ejecutar el hilo (debe recibir un void* y retornar un void*), y el argumento de la funcion anterior.
    iret1 = pthread_create( &h1, NULL, imprimir_mensaje, (void*) planeta1);
    iret2 = pthread_create( &h2, NULL, imprimir_mensaje, (void*) planeta2);
    iret3 = pthread_create( &h3, NULL, imprimir_mensaje, (void*) planeta3);
    iret4 = pthread_create( &h4, NULL, imprimir_mensaje, (void*) planeta4);

    if(iret1) // si iret es 0, ocurrio algun error al crear el hilo.
    {
        fprintf(stderr,"Error codigo: %d\n",iret1);
        exit(1); //si alguno falla, termina la ejecucion
    }
    else if(iret2)
    {
        fprintf(stderr,"Error codigo: %d\n",iret2);
        exit(1);
    }
    else if(iret3)
    {
        fprintf(stderr,"Error codigo: %d\n",iret2);
        exit(1);
    }
    else if(iret4)
    {
        fprintf(stderr,"Error codigo: %d\n",iret2);
        exit(1);
    }
    
    
    printf("pthread_create() de h1 retorna: %d\n", iret1);
    printf("pthread_create() de h2 retorna: %d\n", iret2);
    printf("pthread_create() de h3 retorna: %d\n", iret3);
    printf("pthread_create() de h4 retorna: %d\n", iret4);




    pthread_join( h1, NULL); // el proceso principal espera que h1 terminar antes de continuar su ejecucion.
    pthread_join( h2, NULL); 
    pthread_join( h3, NULL); 
    pthread_join( h4, NULL); 
    
    printf("todos los hilos han terminado y yo me voy!\n\n");

    exit(0);
}
