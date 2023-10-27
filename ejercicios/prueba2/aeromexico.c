#include "tiposAereos.h"

void insertarCola(pasa dat, refs *fila);
void imprimirListaDoble(refs fila);
void insertarColaOrdenada(pasa dat, refs *filaO);
void filtrarPasajeros(refs fila, char let);
void navegarCola(refs *fila, nav *nave);

int main (int argc, char *argv[])
{
    refs cola, colaOrdenada;
    FILE *fp;
    pasa datos;
    nav nave;

    char op;
    char letra;

    cola.inicio = NULL;
    cola.aux = NULL;
    cola.fin = NULL;

    colaOrdenada.inicio = NULL;
    colaOrdenada.aux = NULL;
    colaOrdenada.fin = NULL;

    nave.refInicio = NULL;
    nave.aux = NULL;

    fp = fopen(argv[1], "r");
    if(fp == NULL)
    {
        printf("\nArchivo no disponible.\n");
        exit(1);
    }

    while(fscanf(fp, " %[^\t]%i\n", datos.nombre, &datos.zona) == 2)
    {
        insertarCola(datos, &cola);
        insertarColaOrdenada(datos, &colaOrdenada);
    }
    fclose(fp);

    printf("\nImpresión de la cola: ");
    imprimirListaDoble(cola);

    printf("\n¿Quieres ordenar la cola según la zona de los pasajeros? ['s' | 'n']\n");
    scanf(" %c", &op);
    if(op == 's')
    {
        printf("\nImpresión de la cola ordenada: ");
        imprimirListaDoble(colaOrdenada);
    }

    printf("\n¿Quieres filtrar a los pasajeros que su nombre empiece con cierta letra? ['s' | 'n']\n");
    scanf(" %c", &op);
    if(op == 's')
    {
        printf("\nDame la letra por la cual quieres filtrar a los pasajeros:\n");
        scanf(" %c", &letra); 
        filtrarPasajeros(cola, letra);
    }

    printf("\n¿Quieres navegar la cola pasajaero por pasajero? ['s' | 'n']\n");
    scanf(" %c", &op);
    if(op == 's')
    {
        navegarCola(&cola, &nave);
    }

    return 0;
}