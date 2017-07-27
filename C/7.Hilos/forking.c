#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#define MAX_COUNT  200000


void trabajo_hijo(pid_t resultado_fork)
{
     int   i;

     for (i = MAX_COUNT; i >= 0; i--)
          printf("\t\thijo trabajando (%d:%d), valor = %d\n", getpid(), resultado_fork, i);
     printf("   *** proceso hijo finalizado ***\n");
     return;
}

void trabajo_padre(pid_t resultado_fork)
{
     int   i;

     for (i = 1; i <= MAX_COUNT; i++)
          printf("padre trabajando (%d:%d), valor = %d\n", getpid(), resultado_fork, i);
     printf("*** proceso hijo finalizado ***\n");
     return;
}



void main(void)
{
     pid_t pid;

     pid = fork(); // division del proceso
     if (pid == 0)  // en el proceso padre, pid es 0.
          trabajo_hijo(pid);
     else  //en el proceso hijo, pid el numero asignado por el SO.
          trabajo_padre(pid);
}
