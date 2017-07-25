#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#define   MAX_COUNT  200000


void  trabajo_hijo(void)
{
     int   i;

     for (i = 1; i <= MAX_COUNT; i++)
          printf("\t\thijo trabajando (%d), valor = %d\n", getpid(), i);
     printf("   *** proceso hijo finalizado ***\n");
     return;
}

void  trabajo_padre(void)
{
     int   i;

     for (i = 1; i <= MAX_COUNT; i++)
          printf("padre trabajando (%d), valor = %d\n", getpid(), i);
     printf("*** proceso hijo finalizado ***\n");
     return;
}



void  main(void)
{
     pid_t pid;

     pid = fork();
     if (pid == 0) 
          trabajo_hijo();
     else 
          trabajo_padre();
}
