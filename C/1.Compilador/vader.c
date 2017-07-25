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
