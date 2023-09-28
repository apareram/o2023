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
void latteamericano(nodo *aux2);
void deQueueHist(nodo **ptfirst, nodo **ptlast, FILE *fp2);

int main(int arc, char *argv[])
{
    FILE *fp;
    FILE *fp2;
    cliente persona;
    nodo *inicio; //Stack (LIFO)
    nodo *first, *last; //Cola (FIFO)
    char op;

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

    latteamericano(first);

    fp2 = fopen("historial.txt", "a");
    if (fp2 == NULL)
    {
        printf("\nNo se pudo abrir el archivo de registro.\n");
        exit(1);
    }

    deQueueHist(&first, &last, fp2);

    fclose(fp2);

    printf("\n\nQuieres atender a un cliente (s | n):\n");
    scanf(" %c", &op);
    while(op != 'n')
    {
        fp2 = fopen("historial.txt", "a");
        if (fp2 == NULL)
        {
            printf("\nNo se pudo abrir el archivo de registro.\n");
            exit(1);
        }

        deQueueHist(&first, &last, fp2);

        fclose(fp2);

        printf("\nEstos son los clientes en la cola:\n");
        imprimirLista(inicio);
        imprimirListaFIFO(first);
        latteamericano(first);

        printf("\nQuieres atender a otro cliente (s | n):\n");
        scanf(" %c", &op);

        if(&first == NULL && &last== NULL)
        {
            printf("\nYa no hay más clientes en la cola\n");

        }
    }

    printf("\nEstos son los clientes en la cola:\n");
    imprimirLista(inicio);
    imprimirListaFIFO(first);
    latteamericano(first);

    return 0;
}