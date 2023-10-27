/*
@file listaDoble.c
@brief Una fruteria requiere atender de menjor manera, para esos se diseñó el siguiente programa.
       Se requiere que las frutas para venta se organicen y clasifiquen en una cola. Una vez organizadas
       se reuiqeren hacer algunas acciones y reportes. Para lograr esto se requieren los siguientes 
       objetivos:
       1) Cargar el inventario de frutas desde un archivo de texto ingeresado en la línea de comandos a 
          una lista doblemente enlazada. Al cargarlos se deberan ordenar las frutas en orden acendente
          (A-Z).
       2) Se requiere de una función que permita calcular el valor del inventario de frutas.
       3) Se requiere de una función que actualice los precios de las frutas, permite que el usuario
          ingrese un aumento porcentual del precio. Una vez que los precios fueron actualizados la 
          función lo imprime en pantalla.
@author Alberto Parera Méndez en el examen de Guillermo Gómez
@date 27/10/2023
*/
#include "tipos.h"

void insertarListaDobleA_Z(refs *nav, frut inv);
void imprimirListaDoble(refs nav, float granTotal);
float calcularGranTotal(refs nav);
void actualizarPreciosFrutas(refs *nav, float incr);

int main (int argc, char *argv[])
{
    FILE *fp;
    frut inventario;
    refs navegador;
    float granTotal;
    float incremento;

    navegador.inicio = NULL;
    navegador.fin = NULL;
    navegador.aux = NULL;

    fp = fopen(argv[1], "r");
    if(fp == NULL)
    {
        printf("\nArchivo no disponible.\n");
        exit(1);
    }
    while(fscanf(fp, "%s\t%f\t%f\n", inventario.fruta, &inventario.precio, &inventario.inventario) == 3)
    {
        insertarListaDobleA_Z(&navegador, inventario);
    }
    fclose(fp);

    granTotal = calcularGranTotal(navegador);
    
    printf("\n\nValor del inventario de la fruteria:\n");
    imprimirListaDoble(navegador, granTotal);

    printf("\n\nDame en porcentaje (sin el simbolo) de incremento de precios:\n");
    scanf(" %f", &incremento);
    
    printf("\n\nPrecios actualizados con un aumento del %f:\n", incremento);
    actualizarPreciosFrutas(&navegador, incremento);
    granTotal = calcularGranTotal(navegador);
    imprimirListaDoble(navegador, granTotal);

    return 0;
}