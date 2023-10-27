/*
@file funciones.c
@brief Este archivo contiene las funciones que son llamadas desde frutas.c. 
@author Alberto Parera Méndez en el examen de Guillermo Gómez
@date 27/10/2023
*/

#include "tipos.h"

/*
@brief Esta función agrega un nodo en una lista doble, en donde se validan
       dos condiciones:
       1) Si la lista esta vacía, nuevo toma el valor de los datos que se
          están leyendo del archivo de texto e inicio y fin apuntan a donde
          apunta nuevo, que en esta caso es NULL.
       2) Si la lista contiene un elemento, agrega el nuevo nodo a la 
          derecha del existente, hace esto asignando a el apuntador de la 
          izquierda del nuevo nodo el valor de fin, mueve nav para que 
          apunte a este nuevo elemento y manda fin a apintar a este también.
       3) Hace validaciónes para insertar los contenidos en orden acendiente
          (A-Z) Para esto compara si el valor leído es menor al primero, si
          lo es lo incerta antes de este. Si es mayor al último, si lo es este
          nuevo se vuelve el nuevo último. Si se encuentra entre el primero y
          el último checa la lista para cual es su lugar.
@author Alberto Parera Méndez en el examen de Guillermo Gómez
@date 27/10/2023
@param *nav es un apuntador de tipo refs, una caja con tres apuntadores: 
       inicio, aux y fin.
@param inv es un dato del tipo frut, que contienee la información las frutas.
*/
extern void insertarListaDobleA_Z(refs *nav, frut inv) 
{
    nodo *nuevo;
    nodo *actual;
    actual = nav->inicio;

    nuevo = (nodo *)malloc(sizeof(nodo));
    
    if (nuevo == NULL) {
        printf("\nNo hay memoria disponible.\n");
        exit(1);
    }

    nuevo->izq = NULL;
    nuevo->der = NULL;
    nuevo->inventario = inv;

    if(nav->inicio == NULL && nav->fin == NULL) 
    {
        nav->inicio = nuevo;
        nav->fin = nuevo;
    }
    else
    {
        if(inv.fruta[0] < nav->inicio->inventario.fruta[0])
        {
            nuevo->der = nav->inicio;
            nav->inicio->izq = nuevo;
            nav->inicio = nuevo;
        }
        else
        {
            if (inv.fruta[0] > nav->fin->inventario.fruta[0]) 
            {
                nuevo->izq = nav->fin;
                nav->fin->der = nuevo;
                nav->fin = nuevo;
            }
            else
            {
                while((actual != NULL) && (actual->inventario.fruta[0] < inv.fruta[0])) 
                {
                    actual = actual->der;
                }
                if(actual != NULL)
                {
                    nuevo->der = actual;
                    nuevo->izq = actual->izq;
                    if(actual->izq != NULL) 
                    {
                        actual->izq->der = nuevo;
                    }
                    actual->izq = nuevo;
                }
            }
        }
    }

    return;
}

/*
@brief Esta función clacula el gran total del elemnto precio de la lista doble.
@author Alberto Parera Méndez en la clase de Guillermo Gómez
@date 27/10/2023
@param nav es un apuntador de tipo refs, una caja con tres apuntadores: inicio, aux y fin.
@return tot es un flotante conteniendo el total de los precios
*/
float calcularGranTotal(refs nav)
{
    float tot = 0.0;

    nav.aux = nav.inicio;
    
    if((nav.inicio == NULL) && (nav.fin == NULL))
    {
        printf("\nLista vacía.\n");
    }
    while(nav.aux != NULL)
    {
        tot = tot + (nav.aux->inventario.precio)*(nav.aux->inventario.inventario);
        nav.aux = nav.aux->der;
    }

    return tot;
}

/*
@brief Esta función imprime en pantalla lo que se encuentra en la lista doble.
@author Alberto Parera Méndez en el examen de Guillermo Gómez
@date 27/10/2023
@param nav es un apuntador de tipo refs, una caja con tres apuntadores: inicio, aux y fin.
*/
extern void imprimirListaDoble(refs nav, float granTotal)
{
    nav.aux = nav.inicio;
    
    if((nav.inicio == NULL) && (nav.fin == NULL))
    {
        printf("\nLista vacía.\n");
    }
    while(nav.aux != NULL)
    {
        printf("\n%s\t", nav.aux->inventario.fruta);
        printf("$%f\t", nav.aux->inventario.precio);
        printf("%f\n", nav.aux->inventario.inventario);
        nav.aux = nav.aux->der;
    }
    printf("\nGran total:\t$%f\n", granTotal);

    return;
}

/*
@brief Esta función actualiza los precios de una lista doble según el incremento porcentual que
       ingrese el usuario.
@author Alberto Parera Méndez en la clase de Guillermo Gómez
@date 27/10/2023
@param *nav es un apuntador de tipo refs, una caja con tres apuntadores: inicio, aux y fin.
@param incr es el incremento porcentual que el usuario desea aplicarle a todas las frutas.
*/
void actualizarPreciosFrutas(refs *nav, float incr)
{
    nav->aux = nav->inicio;
    
    if((nav->inicio == NULL) && (nav->fin == NULL))
    {
        printf("\nLista vacía.\n");
    }
    while(nav->aux != NULL)
    {
        nav->aux->inventario.precio = nav->aux->inventario.precio * (1 + incr / 100);
        nav->aux = nav->aux->der;
    }

    return;
}