/*
@file valRet.c
@brief Este ejemplo es para comprender el uso del valor de retorno de una 
       función; es un atajo útil en lenguaje C.
       Ejemplo: haga un programa que se quede en un ciclo leyendo números enteros 
       positivos (naturales). Si se ingresa un dato diferente, el programa termina el
       y entrga la suma total de los reales.
@author Alberto Parera Méndez
@date 24/08/2023
*/

#include <stdio.h>
#define PI 3.14159

int main(void)
{
    int num, suma = 0;

    printf("\nEste programa suma naturales, dame un número: ");

    while(scanf(" %d", &num) == 1 && (num >= 0))
    {
        suma = suma + num;
        printf("\nDame otro número: ");

    }

    printf("\nTu suma de naturales es: %d\n", suma);

    printf("\nEl valor de PI x suma es: %f\n", suma*PI);

    return 0;
}