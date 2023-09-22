/*
@file apuntArreglo.c
@brief Haga un programa en C que permita encontear el promedio de 5 valores
       enteros y que indique cuál fue el mayor y el menor de los datos 
       ingresados.
       Características de código:
       1) Haga un header file para las declaraciones y tipos comunes.
       2) Haga una función externa que calcule y entregue el promedio, el 
          menor y el mayor de los datos.
@autor Alberto Parera Méndez en la clase de Guillermo Gómez
@fecha 29/08/2023
*/

#include "defTipos.h"

float darResultados(int tam, int arreglo[], int *min, int *max);
void capturaArreglo(int tam, int arreglo[]);

int main(void)
{
    int menor, mayor, i;
    int arregloEnteros[TAM];
    float promedio;

    printf("\nLas direcciones de memoria son; de menor: %p, mayor: %p, arregloEnetros: %p\n", &menor, &mayor, arregloEnteros);


    capturaArreglo(TAM, arregloEnteros); 
    promedio = darResultados(TAM, arregloEnteros, &menor, &mayor);
    printf("\nEl promedio es: %f el mayor es: %d y el menor es: %d\n", promedio, mayor, menor);

    return 0;   
}