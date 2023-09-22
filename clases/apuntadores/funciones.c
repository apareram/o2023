/*
@file funciones.c
@brief Este archivo tiene las funciones extermas que son utilizadas en el
       programa apuntArreglo.c
@autor Alberto Parera Méndez en la clase de Guillermo Gómez
@fecha 29/08/2023
*/

#include "defTipos.h"

/*
@brief Esta función recibe un arreglo de enteros y calcula el promedio de
       de los números; ecuentra los valores que son el menor y el mayor de
       ese conjunto de datos 
@autor: Alberto Parera Mendez en la clase de Guillermo Gómez
@fecha 31/08/2023
@param tam es tamaño del arreglo entero
@param arreglo[] es un arreglo de enteros
@param *min es un apuntador de tipo entero, el menor
@param *max es un apuntador de tipo entero, el mayor
@return promedio que es el resultado real del promedio de números
*/

extern float darResultados(int tam, int arreglo[], int *min, int *max)
{
    int i, suma = 0;
    float promedio;

    *min = arreglo[0];
    *max = arreglo[0];

    printf("\nLas direcciones de memoria son; de *min: %p, de *max: %p y de arreglo: %p\n", &min, &max, arreglo);


    for(i = 0; i < tam; i++)
    {
        if(*min > arreglo[i])
        {
            *min = arreglo[i];
        }

        if(*max < arreglo[i])
        {
            *max = arreglo[i];
        }

        suma = suma + arreglo[i];
    }  

    promedio = (suma*1.0)/tam;

    return promedio;
}

/*
@brief Esta función recibe un arreglo de enteros para que se capturen
       los datos 
@autor: Alberto Parera Mendez en la clase de Guillermo Gómez
@fecha 31/08/2023
@param tam es tamaño del arreglo entero
@param arreglo[] es un arreglo de enteros
@return void
*/

extern void capturaArreglo(int tam, int arreglo[])
{
    int i;

    for(i = 0; i < tam; i++)
    {
        printf("\nDame el dato %d del arreglo: \n", i+1);
        scanf(" %d", &arreglo[i]); //scanf(" %d", (arreglo + 1));
    }

    return;
}

