/*
@file listaLIFO2.c
@brief Este ejemplo es para manipular una lista LIFO de nodos que están
       definidos con una parte de nombre (string) y un apuntador next al
       siguiente nodo del mismo tipo:
       1) Define una variable apuntador de nombre inicio de tipo nodo y 
          asígnela a NULL. Con esto la variable indica que es una lista
          vacia.
       2) Haga una función de nombre push que inserte un nuevo nodo con 
          una palabra que ingrese el usuario y en cadenada la lista de 
          forma LIFO.
       3) El ingreso de los datos (cadenas) serán desde un archivo de texto
          en la línea de comandos.
@author Alberto Parera Méndez en la clase de Guillermo Gómez
@date 22/09/2023
*/

#include "defTipos.h"

nodo *push(char pal[], nodo *pt);
void comprobarLista(nodo *pt);
void dibujarNodos(nodo *pt);
nodo *pop(nodo *pt);
nodo *borrarTodos(nodo *pt);
nodo *eliminarPalabra(char pal[], nodo *pt);

int main(int argc, char *argv[])
{
    nodo *inicio;
    char pal[40];
    FILE *fp;

    fp = fopen(argv[1], "r");
    if(fp == NULL)
    {
        printf("\nArchivo no disponible\n");
        exit(1);
    }

    inicio = NULL;
    printf("\nEste programa inserta palabras en una lista LIFO de un archivo de texto: ");
    
    while(fscanf(fp, "%s", pal) == 1)
    {
        inicio = push(pal, inicio);
    }
    fclose(fp);

    comprobarLista(inicio);

    dibujarNodos(inicio);

    /*inicio = pop(inicio);
    comprobarLista(inicio);*/
    
    printf("\nDame la palabra que deseas borrar: ");
    scanf("%s", pal);
    eliminarPalabra(pal, inicio);
    
    inicio = borrarTodos(inicio);
    
    return 0;
}