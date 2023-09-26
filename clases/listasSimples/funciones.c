/*
@file funciones.c
@brief Este ejemplo archivo contiene las funciones que son llamadas desde
       listaLIFO.c. Permite crear una lista simplre y varias operaciones
       en los nodos de la lista.
@author Alberto Parera Méndez en la clase de Guillermo Gómez
@date 21/09/2023
*/


#include "defTipos.h"

/*
@brief Esta función agrega un nodo al inicio de la lista con la operación
       en listaLIFO.c.
@author Alberto Parera Méndez en la clase de Guillermo Gómez
@date 21/09/2023
@param pal[] y es una cadena de chars.
@param *pt es un apuntador del tipo nodo.
@return *pt es un apiuntador de tipo nodo que devuelve el nuevo inicio de
        la lista.
*/
extern nodo *push(char pal[], nodo *pt)
{
    nodo *nuevo;

    nuevo = (nodo *)malloc(sizeof(nodo));
    if(nuevo == NULL)
    {
        printf("\nNo hay memoria disponible.\n");
        exit(1);
    }
    strcpy(nuevo->palabra, pal);
    nuevo->next = pt;
    pt = nuevo;

    return pt;
}

extern void comprobarLista(nodo *pt)
{
    printf("\nComprobando que la lista está completa:\n");
    if(pt != NULL)
    {
        while(pt != NULL)
        {
            printf("%s\n", pt->palabra);
            pt = pt->next;
        }
    }
    else
    {
        printf("\nLista vacía\n");
    }
    return;
}

extern void dibujarNodos(nodo *pt)
{
    printf("\nGráfico de los apuntadores:\n");
    printf("\ninicio(%p)->", pt);
    if(pt != NULL)
    {
        while(pt != NULL)
        {
            printf("|%s||(%p)|->", pt->palabra, pt->next);
            pt = pt->next;
        }
        printf("NULL\n");
    }
    else
    {
        printf("NULL\n");
        printf("\nLista vacía\n");
    }
    return;
}

extern nodo *pop(nodo *pt)
{
    nodo *borra;
    if(pt != NULL)
    {
        borra = pt;
        pt = pt->next;
        free(borra);
    }
    else
    {
        printf("\nLista vacía\n");
    }

    return pt;
}

extern nodo *borrarTodos(nodo *pt)
{
    while(pt != NULL)
    {
        pt = pop(pt);
        comprobarLista(pt);
    }

    return pt;
}

extern nodo *eliminarPalabra(char pal[], nodo *pt)
{
    nodo *ubica, *recorre;
    ubica = pt;
    recorre = pt;

    if(strcmp(pt->palabra, pal) == 0)
    {
        pt = pop(pt);
    }
    else
    {
        while(recorre != NULL)
        {
            recorre = recorre->next;
            if((recorre != NULL) && (strcmp(pal, recorre->palabra) == 0))
            {
                ubica->next = recorre->next;
                free(recorre);
                break;
            }
            ubica= recorre;
        }
    }

    return pt;
}