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

extern void imprimirColaCirc(nodo *first, nodo *last){
    nodo *nuevo = first;


    if ((first == NULL) && (last == NULL))
    {
        printf("\nCola vacía.\n");
        return;
    }

    do 
    {
        printf("\n%s\t", nuevo->nombre);
        printf("%i\n", nuevo->prioridad);
        nuevo = nuevo->next;
    } while (nuevo != first);


    return;
}

extern void deQueueFirst(nodo **ptFirst, nodo **ptLast)
{
    nodo *nuevo = *ptFirst;

    if(((*ptFirst == NULL) && (*ptLast == NULL)) || (*ptFirst == *ptLast))
    {
        free(nuevo); 
        *ptFirst = NULL;
        *ptLast = NULL;
        printf("\nLa cola está vacía, no se puede eliminar nada.\n");
        return;
    }
    else
    {
        if(*ptFirst != *ptLast)
        {
            *ptFirst = (*ptFirst)->next;
            free(nuevo); 
            nuevo = *ptFirst;
            (*ptLast)->next = *ptFirst;
        }
    }

    return;
}
