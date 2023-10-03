/*
@file listaFIFO.c
@brief Este programa permite la creación de una lista FIFO de palabras.
       1) Haga una función que ponga en cola palabras que se leen  de un
          archivo de texto que contiene una frase.
       2) Haga una función que permita atender/borrar.
@author Alberto Parera Méndez en la clase de Guillermo Gómez
@date 26/09/2023
*/

#include "defFIFO.h"

void enQueue(char pal[], nodo **ptInicio, nodo **ptUiltmo);
void deQueue(nodo **ptInicio, nodo **ptUiltmo);
void imprimirListaFIFO(nodo *aux);

int main(int argc, char *argv[])
{   
    FILE *fp;
    nodo *primero, *ultimo;
    char palabra[40];
    char opcion = 's';

    primero = NULL;
    ultimo = NULL;

    fp = fopen(argv[1], "r");
    if(fp == NULL)
    {
        printf("\nArchivo no disponible\n");
        exit(1);
    }
    while (fscanf(fp, "%s", palabra) == 1)
    {
        enQueue(palabra, &primero, &ultimo);
    }
    fclose(fp);

    imprimirListaFIFO(primero);

    while (opcion == 's')
    {
        printf("\nDeseas borrar el nodo (deQueue): ");
        scanf(" %c", &opcion);
        if(opcion == 's')
        {
            deQueue(&primero, &ultimo);
        }
        imprimirListaFIFO(primero);
    }

    return 0;
}