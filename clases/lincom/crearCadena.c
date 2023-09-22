/*
@file crearCadena.c
@brief este es un ejemplo de sprintf
@autor Alberto Parera Mendez
@fecha 22/08/2023
*/
#include <stdio.h>

int main(void)
{
    float peso, altura;
    char nombre[40], cadena[100];

    printf("\nDame el nombre: ");
    scanf("%s", nombre);
    printf("\nDame su peso y altura: ");
    scanf("%f %f", &peso, &altura);
    sprintf(cadena, "Esta persona %s pesa %f y mide %f", nombre, peso, altura);
    printf("\n%s\n", cadena);

    return 0;
}