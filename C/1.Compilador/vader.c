/*
Escuela de veranillo en computacion de alto rendimiento.
24-28 julio 2017
CNCA, CeNAT.

M. Sc. Ricardo Roman-Brenes, PRIS-Lab/EIE/UCR
ricardo.roman@ucr.ac.cr
*/

#include <stdio.h>

int main(int argc, char** argv)
{
    int i = 0;
    int acc = 0;
    for(i; i < 1000; i++)
    {
        acc += i;
    }
    printf("no, yo soy tu padre... %d!\n", acc);
    return 0;
}
