/*
@file listaLIFO.c
@brief Este ejemplo es para manipular una lista LIFO de nodos que están
       definidos con una parte de nombre (string) y un apuntador next al
       siguiente nodo del mismo tipo:
       1) Define una variable apuntador de nombre inicio de tipo nodo y 
          asígnela a NULL. Con esto la variable indica que es una lista
          vacia.
       2) Haga una función de nombre push que inserte un nuevo nodo con 
          una palabra que ingrese el usuario y en cadenada la lista de 
          forma LIFO. El usuario va tecleando palabras, se insertan todas
          excepto "salir", con esta palabra termina la inserción.
@author Alberto Parera Méndez en la clase de Guillermo Gómez
@date 19/09/2023
*/

#include "defTipos.h"

nodo *push(char pal[], nodo *pt);
void comprobarLista(nodo *pt);
void dibujarNodos(nodo *pt);
nodo *pop(nodo *pt);

int main(int argc, char *argv[])
{
    nodo *inicio;
    char pal[40];

    inicio = NULL;
    printf("\nEste programa inserta palabras en una lista LIFO, dame tu palabra: ");
    scanf("%s", pal);
    while(strcmp(pal, "salir") != 0)
    {
        inicio = push(pal, inicio);
        printf("\nDame otra palabra para insertar en LIFO: ");
        scanf("%s", pal);
    }

    comprobarLista(inicio);

    dibujarNodos(inicio);

    inicio = pop(inicio);
    comprobarLista(inicio);
    

    return 0;
}