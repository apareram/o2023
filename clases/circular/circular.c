/*
@file circular.c
@brief Este ejemplo crea una lista simple circular que simula una cola de
       personas que cuentan con un número de prioridad.
       1) Cree una lista circular a partir de los datos de un archivo de
          texto.
       2) Imprima la lista creada.
*/

#include "defCircular.h"

void enQueueCirc(nodo **ptPrimero, nodo **ptUltimo, char nom[], int pri);
void imprimirColaCirc(nodo *first, nodo *last);

int main(int argc, char *argv[])
{
    FILE *fp;
    nodo *primero, *ultimo;
    char nombre[80];
    int prioridad;

    primero = NULL;
    ultimo = NULL;

    fp = fopen(argv[1], "r");
    if(fp == NULL)
    {
        printf("\nArchivo no disponible.\n.");
        exit(1);
    }

    while(fscanf(fp, " %[^\t]%d", nombre, &prioridad) == 2)
    {
        enQueueCirc(&primero, &ultimo, nombre, prioridad);
    }
    fclose(fp);

    imprimirColaCirc(primero, ultimo);

    return 0;
}
