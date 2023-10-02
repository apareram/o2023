/*
@file funciones.c
@brief Este  archivo contiene las funciones que son llamadas desde
       banco.c. 
@author Alberto Parera Méndez
@date 29/09/2023
*/

#include "tipos.h"

/*
@brief Esta función agrega un nodo al inicio de la lista con la operación
       en autos.c.
@author Alberto Parera Méndez
@date 29/09/2023
@param autos estructura de tipoAutos.
@param *pt es un apuntador del tipo nodo.
@return *pt es un apiuntador de tipo nodo que devuelve el nuevo inicio de
        la lista.
*/
extern nodo *push(tipoclientes clientes, nodo *pt)
{
    nodo *nuevo;

    nuevo = (nodo *)malloc(sizeof(nodo));
    if(nuevo == NULL)
    {
        printf("\nNo hay memoria disponible.\n");
        exit(1);
    }
    nuevo->clientes = clientes;
    nuevo->next = pt;
    pt = nuevo;

    return pt;
}

/*
@brief Esta función copia lo que se encuentra en el acrhivo de texto y lo
       coloca en una lista LIFO.
@author Alberto Parera Méndez
@date 29/09/2023
@param nomarch[] es una cadena de chars que contiene el nombre del archivo de
       texto.
@param *pt es un apuntador del tipo nodo.
@return *pt es un apiuntador de tipo nodo que devuelve el nuevo inicio de
        la lista.
*/
extern nodo *leerDatos(char nomArch[])
{
    FILE *fp;
    nodo *pt;
    tipoclientes clientes;

    fp = fopen(nomArch, "r");
    if(fp == NULL)
    {
        printf("\nArchivo no disponible\n");
        exit(1);
    }

    pt = NULL;
    
    while(fscanf(fp, " %[^\n]\t%s\t%i\t%f\n", clientes.nombre, clientes.curp, &clientes.cp, &clientes.limcred) == 4)
    {
        pt = push(clientes, pt);
    }
    fclose(fp);

    return pt;
}

/*
@brief Esta función imprime en pantalla lo que se encuentra en la lista 
       LIFO.
@author Alberto Parera Méndez
@date 29/09/2023
@param *pt es un apuntador del tipo nodo.
*/
extern void imprimirLista(nodo *pt)
{
    printf("\nDatos en el archivo son:\n");
    if(pt != NULL)
    {
        while(pt != NULL)
        {
            printf("%s\t%s\t%i\t%f\n", pt->clientes.nombre,pt->clientes.curp, pt->clientes.cp, pt->clientes.limcred);
            pt = pt->next;
        }
    }
    else
    {
        printf("\nLista vacía\n");
    }
    return;
}