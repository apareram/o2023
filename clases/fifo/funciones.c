#include "defFIFO.h"

extern void enQueue(char pal[], nodo **ptInicio, nodo **ptUiltmo)
{
    nodo *nuevo;

    nuevo = (nodo *)malloc(sizeof(nodo));
    if(nuevo == NULL)
    {
        printf("\nNo hay memoria disponible.\n");
        exit(1);
    }
    strcpy(nuevo->palabra, pal);
    nuevo->next = NULL;

    if((*ptInicio == NULL) && (*ptUiltmo == NULL))
    {
        *ptInicio = nuevo;
        *ptUiltmo = nuevo;
    }
    else
    {
        (*ptUiltmo)->next = nuevo;
        *ptUiltmo = nuevo;
    }

    return;
}

extern void imprimirListaFIFO(nodo *aux)
{
    printf("\n");
    while(aux != NULL)
    {
        printf("%s\t", aux->palabra);
        aux = aux->next;
    }
    printf("\n\n");

    return;
}

extern void deQueue(nodo **ptInicio, nodo **ptUiltmo)
{
    nodo *borra;
    borra = *ptInicio;
    
    if((*ptInicio == NULL) && (*ptUiltmo == NULL))
    {
        printf("\nLista vacía.\n");
    }
    else
    {
        if(*ptInicio == *ptUiltmo) //un solo nodo en cola
        {
            printf("\nSe va a borrar la palabra: %s", borra->palabra);
            *ptInicio = NULL;
            *ptUiltmo = NULL;
            free(borra);
        }
        else
        {
            printf("\nSe va a borrar la palabra: %s", borra->palabra);
            *ptInicio = (*ptInicio)->next;
            free(borra);
        }
    }
}