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

/*
@brief Esta función imprime los contenidos de una lista circular de clientes
       con prioridad.
@author Alberto Parera
@date 10/10/2023
@param first es un apuntador de tipo nodo.
@param last es un apuntador de tipo nodo.
@return void.
*/
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

extern void deQueueCirc(nodo **ptPrimero, nodo **ptUltimo)
{
    nodo *borra;

    if ((*ptPrimero == NULL) && (*ptUltimo == NULL))
    {
        printf("\nNo puedo borrar, lista vacía.\n");
    }    
    else
    {
        borra = *ptPrimero;
        if(*ptPrimero == *ptUltimo)
        {
            *ptPrimero = NULL;
            *ptUltimo = NULL;
            free(borra);
        }
        else
        {
            *ptPrimero = (*ptPrimero)->next;
            (*ptUltimo)->next = *ptPrimero;
            free(borra);
        }

    }

    return;
}

extern void borrarTodos(nodo **ptPrimero, nodo **ptUltimo)
{
    char res;

    printf("\n¿Quieres borrar todos los nodos? ['s' | 'n']:\n");
    scanf(" %c", &res);
    if(res == 's')
    {
        while((*ptPrimero != NULL) && (*ptUltimo != NULL))
        {
            deQueueCirc(ptPrimero, ptUltimo);
        }
    }
    return;
}