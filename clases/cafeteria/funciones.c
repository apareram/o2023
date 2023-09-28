/*
@file funciones.c
@brief Este  archivo contiene las funciones que son llamadas desde cafe.c.
       Estas funciones son para crear y administrar listas de Stacks y 
       Cola.
@author Alberto Parera Méndez en clase de Guillermo Gómez
@date 26/09/2023
*/

#include "tipos.h"

/*
@brief Esta función agrega una lista LIFO o Stack de clientes.
@author Alberto Parera Méndez en clase de Guillermo Gómez
@date 28/09/2023
@param datos es una estructura de tipo cliente.
@param *pt es un apuntador del tipo nodo.
@return *pt es un apiuntador de tipo nodo que devuelve el nuevo inicio del
        struct.
*/
extern nodo *push(cliente datos, nodo *pt)
{
    nodo *nuevo;

    nuevo = (nodo *)malloc(sizeof(nodo));
    if(nuevo == NULL)
    {
        printf("\nNo hay memoria disponible.\n");
        exit(1);
    }
    nuevo->ticket = datos;
    nuevo->next = pt;
    pt = nuevo;

    return pt;
}

extern void imprimirLista(nodo *aux)
{
    if(aux != NULL)
    {
        while(aux != NULL)
        {
            printf("\n%s\t%s\t%f\n", aux->ticket.nombre, aux->ticket.cafe, aux->ticket.precio);
            aux = aux->next;
        }
    }
    else
    {
        printf("\nLista vacía\n");
    }

    return;
}

extern void enQueue(cliente datos2, nodo **ptfirst, nodo **ptlast)
{
    nodo *nuevo;

    nuevo = (nodo *)malloc(sizeof(nodo));
    if(nuevo == NULL)
    {
        printf("\nNo hay memoria disponible.\n");
        exit(1);
    }
    nuevo->ticket = datos2;
    nuevo->next = NULL;

    if((*ptfirst == NULL) && (*ptlast == NULL))
    {
        *ptfirst = nuevo;
        *ptlast = nuevo;
    }
    else
    {
        (*ptlast)->next = nuevo;
        *ptlast = nuevo;
    }

    return;
}

extern void imprimirListaFIFO(nodo *aux2)
{
    while(aux2 != NULL)
    {
        printf("\n%s\t%s\t%f\n", aux2->ticket.nombre, aux2->ticket.cafe, aux2->ticket.precio);
        aux2 = aux2->next;
    }
    printf("\n");

    return;
}