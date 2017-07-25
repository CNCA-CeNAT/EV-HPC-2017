
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


void* imprimir_mensaje(void* mensaje)
{
     char* m;
     m = (char *) mensaje;
     printf("Saludos terricolas desde el %s\n", m);
}

int main(int argc, char** argv)
{
    pthread_t thread1, thread2;
    const char *message1 = "hilo1";
    const char *message2 = "hilo2";
    int  iret1, iret2;

    /* Create independent threads each of which will execute function */

    iret1 = pthread_create( &thread1, NULL, imprimir_mensaje, (void*) message1);
    if(iret1)
    {
        fprintf(stderr,"Error codigo: %d\n",iret1);
        exit(1);
    }
    printf("pthread_create() retorna: %d\n", iret1);

    iret2 = pthread_create( &thread2, NULL, imprimir_mensaje, (void*) message2);
    if(iret2)
    {
        fprintf(stderr,"Error codigo: %d\n",iret2);
        exit(1);
    }
    printf("pthread_create() retorna: %d\n", iret2);




    pthread_join( thread1, NULL);
    pthread_join( thread2, NULL); 

    exit(0);
}
