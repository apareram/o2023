/*
@file arregloReales.c
@brief Haga un programa en C que permita crear un arreglo de reales del 
       tamaño que indique el usuario.
       Haga las siguientes funciones en un archivo extra:
       1) sumarReales, que reciba el arreglo y entregue la suma.
@autor Alberto Parera Méndez en la clase de Guillermo Gómez
@fecha 01/09/2023
*/
#include "defTipos.h"

float sumarReales(float arreglo[], int tam);

int main(void)
{
    int tam;
    float reales;
    float *apReales;

    printf("\nDame el tamaño de reales que desees sumar: ");
    scanf("%d", &tam);

    apReales = (float *)malloc(tam * sizeof(float));

    if(apReales == NULL)
    {
        printf("\nNo hay memoria disponible\n");
        exit(1);
    }

    printf("\nLa suma de tur reales es: %f\n", sumarReales(apReales, tam));

    free(apReales);

    return 0;
}