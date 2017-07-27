/*
Escuela de veranillo en computacion de alto rendimiento.
24-28 julio 2017
CNCA, CeNAT.

M. Sc. Ricardo Roman-Brenes, PRIS-Lab/EIE/UCR
ricardo.roman@ucr.ac.cr
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <limits.h>


int main(int argc, char** argv) {


    ///////////////////////////////////////
    // tipos numericos
    ///////////////////////////////////////

    ///////////////
    /// enteros ///
    ///////////////
    char _entero_1bytes = 1;
    short _entero_2bytes = 1;
    int _entero_4bytes = 1;
    long _entero_8bytes = 1; // long int y long long

    // 2^bits -1
    printf("bytes de char:\t%d\n", sizeof (_entero_1bytes));
    printf("bytes de short:\t%d\n", sizeof (_entero_2bytes));
    printf("bytes de int:\t%d\n", sizeof (_entero_4bytes));
    printf("bytes de long:\t%d\n", sizeof (_entero_8bytes));

    unsigned int _sin_signo_4bytes = 1;

    printf("bytes de int sin signo:\t%d\n", sizeof (_sin_signo_4bytes));

    ///////////////
    // decimales //
    ///////////////

    float _decimal_4bytes = 340282346638528859811704183484516925440.0f;
    double _decimal_8bytes = 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0;

    printf("bytes de float:\t%d\n", sizeof (_decimal_4bytes));
    printf("bytes de double:\t%d\n", sizeof (_decimal_8bytes));
    // IEEE754

    //tipos de texto
    char _texto_1bytes = '!';

    printf("bytes de char:\t%d\n", sizeof (_texto_1bytes));

    //tipos de arreglo
    char _texto_6entradas[6];
    _texto_6entradas[0] = '@';
    _texto_6entradas[1] = '#';
    _texto_6entradas[2] = '$';
    _texto_6entradas[3] = '%';
    _texto_6entradas[4] = '&';
    _texto_6entradas[5] = '\0';

    printf("bytes de char 0:\t%d -> %c\n", sizeof (_texto_6entradas[0]), _texto_6entradas[0]);
    printf("bytes de char 1:\t%d -> %c\n", sizeof (_texto_6entradas[1]), _texto_6entradas[1]);
    printf("bytes de char 2:\t%d -> %c\n", sizeof (_texto_6entradas[2]), _texto_6entradas[2]);
    printf("bytes de char 3:\t%d -> %c\n", sizeof (_texto_6entradas[3]), _texto_6entradas[3]);
    printf("bytes de char 4:\t%d -> %c\n", sizeof (_texto_6entradas[4]), _texto_6entradas[4]);
    printf("bytes de char 5:\t%d -> %c\n", sizeof (_texto_6entradas[5]), _texto_6entradas[5]);

    printf("bytes de todo el arreglo char:\t%d -> %s\n", sizeof (_texto_6entradas), _texto_6entradas);



    int _entero_6entradas[6];
    _entero_6entradas[0] = 10;
    _entero_6entradas[1] = 11;
    _entero_6entradas[2] = 12;
    _entero_6entradas[3] = 13;
    _entero_6entradas[4] = 14;
    _entero_6entradas[5] = 15;

    printf("bytes de entero 0:\t%d -> %d\n", sizeof (_entero_6entradas[0]), _entero_6entradas[0]);
    printf("bytes de entero 1:\t%d -> %d\n", sizeof (_entero_6entradas[1]), _entero_6entradas[1]);
    printf("bytes de entero 2:\t%d -> %d\n", sizeof (_entero_6entradas[2]), _entero_6entradas[2]);
    printf("bytes de entero 3:\t%d -> %d\n", sizeof (_entero_6entradas[3]), _entero_6entradas[3]);
    printf("bytes de entero 4:\t%d -> %d\n", sizeof (_entero_6entradas[4]), _entero_6entradas[4]);
    printf("bytes de entero 5:\t%d -> %d\n", sizeof (_entero_6entradas[5]), _entero_6entradas[5]);

    printf("bytes de todo el arreglo entero:\t%d -> %d\n", sizeof (_entero_6entradas), _entero_6entradas); //impresion rara


    //tipo punteros

    double _decimal_variable = 2.2;
    double* _decimal_puntero = &_decimal_variable;

    printf("variable: %lf\n", _decimal_variable);
    printf("direccion de variable: %p\n", &_decimal_variable);
    printf("puntero: %p\n", _decimal_puntero);
    printf("direccion de puntero: %p\n", &_decimal_puntero);
    printf("valor de variable apuntada por puntero: %lf\n", *_decimal_puntero);


    //tipos compuestos (structs)

    typedef struct tipo_compuesto {
        int i;
        double d;
        char c;
        
    } tipo_compuesto;

    tipo_compuesto _estructura;
    _estructura.i = 1;
    _estructura.d = 1.1;
    _estructura.c = '1';
    
    
    return (0);
}

