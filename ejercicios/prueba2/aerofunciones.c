/*
@file aerofunciones.c
@brief Este archivo contiene las funciones que son llamadas desde aeromexico.c. 
@author Alberto Parera Méndez 
@date 26/10/2023
*/

#include "tiposAereos.h"

/*
@brief Esta función agrega un nodo en una lista doble circular, en donde se validan
       dos condiciones:
       1) Si la lista esta vacía, nuevo toma el valor de los datos que se
          están leyendo del archivo de texto e inicio y fin apuntan a donde
          apunta nuevo, que en esta caso es a si mismo por que es una lista
          circular.
       2) Si la lista contiene un elemento, agrega el nuevo nodo a la 
          derecha del existente, hace esto asignando a el apuntador de la 
          izquierda del nuevo nodo el valor de fin de la lista, hace que 
          el apuntador de la derecha de este nuevo nodo apunte al inicio
          de la lista (por que es una lista circular) y manda a los 
          apuntadores de referencia (inicio, aux y fin) a que apunten a
          este nuevo nodo.
@author Alberto Parera Méndez
@date 26/10/2023
@param *fila es un apuntador de tipo refs, una caja con tres apuntadores: 
       inicio, aux y fin.
@param dat es un dato del tipo pasa, que contiene la información de un
       pasajero.
*/
extern void insertarCola(pasa dat, refs *fila)
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

/*
@brief Esta función imprime en pantalla lo que se encuentra en la lista doble circular.
@author Alberto Parera Méndez 
@date 19/10/2023
@param *fila es un apuntador de tipo refs, una caja con tres apuntadores: inicio, aux y fin.
*/
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
            printf("\nPasajero: %s", fila.aux->datos.nombre);
            printf("\tZona: %i\n", fila.aux->datos.zona);
            fila.aux = fila.aux->der;
       }while(fila.aux != fila.inicio); 
    }

    return;
}

/*
@brief Esta función ordena según el número de cuenta de alumnos que se 
       encuentran en un archivo de texto, pra esto se validan las  
       siguientes condiciones:
       1) Si la lista esta vacía, inserta el úncio alumno en la lista
          doble circular.
       2) Si la lista contiene más de un elemento: 
          2.1) Si es mayor al primero: simplemente inserta este alúmno a
               la derecha de el primer nodo y recorre los demás una 
               posicion a la derecha. Para esto el apuntador de la derecha
               de nuevo lo manda a apuntar al inicio de la fila, el de la
               izquierda de nuevo lo manda a apauntar al final de la lista,
               el aountador de la izquierda del primer nodo de la lista lo
               manda a apuntar al nuevo nodo (que es el últmo de la lista),
               el apuntador de la derecha del fin de la lista lo manda a 
               apuntar al nuevo nodo y por último el apuntador de inico de
               la lista lo manda a nuevo.
          2.2) Si es menor al último: simplemente inserta este alúmno a
               la izquierda del último nodo y recorre los demás una 
               posicion a la izquierda. Para esto el apuntador de la 
               izquierda de nuevo lo manda a apuntar al dfin de la fila, el 
               de la derecha de nuevo lo manda a apauntar al inicio de la 
               lista, el apuntador de la derecha del último nodo de la lista 
               lo manda a apuntar al nuevo nodo, el apuntador de la izquierda 
               del inicio de la lista lo manda a apuntar al nuevo nodo y por 
               último el apuntador de fin de la lista lo manda a nuevo.
          2.3) Si se encuentra entre el ultimo y el primero: primero posiciona
               al apuntador auxiliar en el inicio de la lista, después se hace 
               un ciclo; Mientras la cuenta del nuevo dato sea mayor a la 
               cuenta que apunte el axuliar, va a ir recorriendo la posición
               del auxiliar hasta que esta condicion no se cumpla, esto nos
               indica donde tenemos que incertar este nuevo nodo.
               Para incertarlo mandamos al apiuntador de la derecha de este
               nuevo nodo a donde se encuentra aux, mandamos el de la izquierda
               del nuevo nodo al apuntador de la izquierda de donde se encuentr
               el auxiliar, despúes movemos el nodo que apunte auxilar a la 
               derecha (moviendo su apuntador de la izquierda a la derecha de 
               del nuevo) y por último movemos el apuntador de la izquierda de
               este nodo a donde esta el nodo nuevo.
@author Alberto Parera Méndez
@date 16/10/2023
@param *fila es un apuntador de tipo refs, una caja con tres apuntadores: inicio, aux y fin.
@param dat es un dato del tipo pasa, que contienee la información de un pasakero.
*/
extern void insertarColaOrdenada(pasa dat, refs *filaO)
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
        if(nuevo->datos.zona < filaO->inicio->datos.zona)
        {
            nuevo->der = filaO->inicio;
            nuevo->izq = filaO->fin;
            filaO->inicio->izq = nuevo;
            filaO->fin->der = nuevo;
            filaO->inicio = nuevo;
        }
        else 
        {
            if(nuevo->datos.zona > filaO->fin->datos.zona) 
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
                while(nuevo->datos.zona > filaO->aux->datos.zona)
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

extern void filtrarPasajeros(refs fila, char let)
{
    fila.aux = fila.inicio;

    if((fila.inicio == NULL) && (fila.fin == NULL))
    {
        printf("\nNo puedo buscar en una lista vacía.\n");
    }
    else
    {
        printf("\nPasajeros que su nombre empieza con la letra %c:\n", let);
        do
       {    
            if(fila.aux->datos.nombre[0] == let)
            {
                printf("\nPasajero: %s", fila.aux->datos.nombre);
                printf("\tZona: %i\n", fila.aux->datos.zona);
            }
            fila.aux = fila.aux->der;
       }while(fila.aux != fila.inicio); 
    }

    return;
}

void navegarCola(refs fila, nav *nave)
{
    char op;

    nave.refInicio = fila.inicio;
    nave.aux = fila.inicio;

    printf("\n¿Quieres navegar al siguiente pasajero? ['s' para avanzar | 'x' para salir]\n");
    scanf(" %c", &op);
    while(op != 'x')
    {
        nave.aux->nav.nombre = fila.aux->datos.nombre;
        nave.aux->nav.zona = fila.aux->datos.zona;
        printf("\nPasajero: %s", nave.aux->datos.nombre);
        printf("\tZona: %i\n", nave.aux->datos.zona);
        fila.aux = fila.aux->der;
        fila.aux = fila.aux->der;
    }

    return;
}