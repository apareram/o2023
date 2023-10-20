/*
@file listaDobleCircular.c
@brief Este es un programa permite crear una lista doblemente circular
       con los datos de alumnos.txt.
       1) Haga una función que cree una lista doble enlazada.
       2) Verifique con otra finción la integridad de la lista creada.
       3) Cree una segunda lista doble circular que ordene en orden 
          acendente por el número de cuenta.
@author Alberto Parera Méndez en la clase de Guillermo Gómez
@date 17/10/2023
*/
#include "tiposDoble.h"

void insertarCola(alum dat, refs *fila);
void imprimirListaDoble(refs fila);
void insertarColaOrdenada(alum dat, refs *filaO);

int main (int argc, char *argv[])
{
    refs cola, colaOrdenada;
    FILE *fp;
    alum datos;

    cola.inicio = NULL;
    cola.aux = NULL;
    cola.fin = NULL;

    colaOrdenada.inicio = NULL;
    colaOrdenada.aux = NULL;
    colaOrdenada.fin = NULL;

    fp = fopen(argv[1], "r");
    if(fp == NULL)
    {
        printf("\nArchivo no disponible.\n");
        exit(1);
    }

    while(fscanf(fp, "%d\t %[^\t]%f\n", &datos.cuenta, datos.nombre, &datos.promedio) == 3)
    {
        insertarCola(datos, &cola);
        insertarColaOrdenada(datos, &colaOrdenada);

    }

    fclose(fp);

    printf("\nImpresión de la cola: ");
    imprimirListaDoble(cola);

    printf("\nImpresión de la cola ordenada: ");
    imprimirListaDoble(colaOrdenada);

    return 0;
}