#include "tiposDoble.h"

extern void insertarCola(alum dat, refs *fila)
{
    nodo *nuevo;
    
    nuevo = (nodo *)malloc(sizeof(nodo));
    if(nuevo == NULL)
    {
        printf("\nNo hay memoria disponible\n");
        exit(1);
    }
    
    nuevo->datos = dat;

    if((fila->inicio == NULL) && (fila->fin == NULL))
    {
        nuevo->der = nuevo;
        nuevo->izq = nuevo;
        fila->inicio = nuevo;
        fila->fin = nuevo;
    }
    else
    {
        nuevo->izq = fila->fin;
        nuevo->der = fila->inicio;
        fila->fin->der = nuevo;
        fila->inicio->izq = nuevo;
        fila->fin = nuevo;
    }

    return;
}

extern void imprimirListaDoble(refs fila)
{
    fila.aux = fila.inicio;

    if((fila.inicio == NULL) && (fila.fin == NULL))
    {
        printf("\nNo puedo imprimir una lista vacía.\n");
    }
    else
    {
        do
       {
            printf("\nCuenta: %d", fila.aux->datos.cuenta);
            printf("\tNombre: %s", fila.aux->datos.nombre);
            printf("\tPromedio: %f\n\n", fila.aux->datos.promedio);
            fila.aux = fila.aux->der;
       }while(fila.aux != fila.inicio); 
    }

    return;
}

extern void insertarColaOrdenada(alum dat, refs *filaO)
{
    nodo *nuevo;
    nuevo = (nodo *)malloc(sizeof(nodo));
    
    if(nuevo == NULL)
    {
        printf("\nNo hay memoria disponible\n");
        exit(1);
    }
    
    nuevo->datos = dat;
    
    if((filaO->inicio == NULL) && (filaO->fin == NULL))
    {
        nuevo->der = nuevo;
        nuevo->izq = nuevo;
        filaO->inicio = nuevo;
        filaO->fin = nuevo;
    }
    else
    {
        if(nuevo->datos.cuenta < filaO->inicio->datos.cuenta)
        {
            nuevo->der = filaO->inicio;
            nuevo->izq = filaO->fin;
            filaO->inicio->izq = nuevo;
            filaO->fin->der = nuevo;
            filaO->inicio = nuevo;
        }
        else 
        {
            if(nuevo->datos.cuenta > filaO->fin->datos.cuenta)
            {
                nuevo->izq = filaO->fin;
                nuevo->der = filaO->inicio;
                filaO->fin->der = nuevo;
                filaO->inicio->izq = nuevo;
                filaO->fin = nuevo;
            }
            else
            {
                filaO->aux = filaO->inicio->der;
                while(nuevo->datos.cuenta > filaO->aux->datos.cuenta)
                {
                    filaO->aux = filaO->aux->der;
                }
                nuevo->der = filaO->aux;
                nuevo->izq = filaO->aux->izq;
                filaO->aux->izq->der = nuevo;
                filaO->aux->izq = nuevo;
            }
        }
    }
    return;
}
