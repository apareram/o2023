/*
@file cafe.c
@brief Este programa permite administras las colas de clientes de una 
       cafetería. Crea listas LIFO y FIFO para dar de alta los clientes 
       en memoria. Con las pilas y colas podemos crear infromes de datos
       de los clientes
@author Alberto Parera Méndez en clase de Guillermo Gómez
@date 28/09/2023
*/

#include "tipos.h"

nodo *push(cliente datos, nodo *pt);
void imprimirLista(nodo *aux);
void enQueue(cliente datos2, nodo **ptfirst, nodo **ptlast);
void imprimirListaFIFO(nodo *aux2);


int main(int arc, char *argv[])
{
    FILE *fp;
    cliente persona;
    nodo *inicio; //Stack (LIFO)
    nodo *first, *last; //Cola (FIFO)

    inicio = NULL;
    first = NULL;
    last = NULL;

    fp = fopen(argv[1], "r");
    if(fp == NULL)
    {
        printf("\nArcihvo no disponible\n");
        exit(1);
    }
    while(fscanf(fp, " %[^\t]%s\n", persona.nombre, persona.cafe) == 2)
    {
        if(strcmp(persona.cafe, "americano") == 0) //Insertar en el Cola
        {
            persona.precio = 20.00;
            enQueue(persona, &first, &last);

        }
        if(strcmp(persona.cafe, "latte") == 0) //Insertar en el Cola
        {
            persona.precio = 35.00;
            enQueue(persona, &first, &last);
        }
        if(strcmp(persona.cafe, "expres") == 0) //Insertar en el Stack
        {
            persona.precio = 30.00;
            inicio = push(persona, inicio);
        }
    }
    fclose(fp);

    imprimirLista(inicio);

    imprimirListaFIFO(first);

    return 0;
}