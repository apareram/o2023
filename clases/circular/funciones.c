#include "defCircular.h"

extern void enQueueCirc(nodo **ptPrimero, nodo **ptUltimo, char nom[], int pri)
{
    nodo *nuevo;

    nuevo = (nodo *)malloc(sizeof(nodo));
    if(nuevo == NULL)
    {
        printf("\nNo hay memoria disponible.\n");
        exit(1);
    }

    strcpy(nuevo->nombre, nom);
    nuevo->prioridad = pri;

    if((*ptPrimero == NULL) && (*ptUltimo == NULL))
    {
        *ptPrimero = nuevo;
        *ptUltimo = nuevo;
        nuevo->next = nuevo;
    }
    else
    {
        nuevo->next = *ptPrimero;
        (*ptUltimo)->next = nuevo;
        *ptUltimo = nuevo;
    }

    return;
}

extern void imprimirColaCirc(nodo *first, nodo *last)
{

    return;
}
