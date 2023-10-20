/*
@file funLisDub.c
@brief Este archivo contiene las funciones que son llamadas desde
       listaDoble.c. 
@author Alberto Parera Méndez en el examenm de Guillermo Gómez
@date 16/10/2023
*/

#include "tiposDoble.h"

/*
@brief Esta función agrega un nodo en una lista doble, en donde se validan
       dos condiciones:
       1) Si la lista esta vacía, nuevo toma el valor de los datos que se
          están leyendo del archivo de texto e inicio y fin apuntan a donde
          apunta nuevo, que en esta caso es NULL.
       3) Si la lista contiene un elemento, agrega el nuevo nodo a la 
          derecha del existente, hace esto asignando a el apuntador de la 
          izquierda del nuevo nodo el valor de fin, mueve nav para que 
          apunte a este nuevo elemento y manda fin a apintar a este también.
@author Alberto Parera Méndez en la clase de Guillermo Gómez
@date 16/10/2023
@param *nav es un apuntador de tipo refs, una caja con tres apuntadores: 
       inicio, aux y fin.
@param dat es un dato del tipo alum, que contienee la información de un
       alumno.
*/
extern void insertarListaDoble(refs *nav, alum dat)
{
    nodo *nuevo;

    nuevo = (nodo *)malloc(sizeof(nodo));
    if(nuevo == NULL)
    {
        printf("\nNo hay memoria disponible.\n");
        exit(1);
    }

    nuevo->izq = NULL;
    nuevo->der = NULL;
    nuevo->datos = dat;

    if((nav->inicio == NULL) && (nav->fin == NULL))
    {
        nav->inicio = nuevo;
        nav->fin = nuevo;
    }
    else
    {
        nuevo->izq = nav->fin;
        nav->fin->der = nuevo;
        nav->fin = nuevo;
    }

    return;
}

/*
@brief Esta función imprime en pantalla lo que se encuentra en la lista 
       doble.
@author Alberto Parera Méndez en la clase de Guillermo Gómez
@date 16/10/2023
@param *nav es un apuntador de tipo refs, una caja con tres apuntadores: 
       inicio, aux y fin.
*/
extern void imprimirListaDoble(refs nav)
{
    nav.aux = nav.inicio;

    while(nav.aux != NULL)
    {
        printf("\nCueta: %d\t", nav.aux->datos.cuenta);
        printf("Nombre: %s\t", nav.aux->datos.nombre);
        printf("Promedio: %f\n", nav.aux->datos.promedio);
        nav.aux = nav.aux->der;
    }
    if((nav.inicio == NULL) && (nav.fin == NULL))
    {
        printf("\nLista vacía.\n");
    }

    return;
}

/*
@brief Esta función borrael primer nodo que se encuentra en la lista doble. 
       Para hacerlo verifica que la lista no se encuentre vacía. Después 
       verifica a donde apuntan inicio y fin, si son iguales solo hay un
       elemento, los manda a apuntar a NULL y borra lo que se encuentre en 
       el nodo. Si son diferentes, recorre las referencias para que no se 
       pierda la integridad de la lista y borra ese nodo.
@author Alberto Parera Méndez en la clase de Guillermo Gómez
@date 16/10/2023
@param *nav es un apuntador de tipo refs, una caja con tres apuntadores: 
       inicio, aux y fin.
*/
extern void borrarPrimero(refs *nav)
{
    nav->aux = nav->inicio;
    if((nav->inicio == NULL) && (nav->fin == NULL))
    {
        printf("\nNo se puede borrar un nodo, la lista se encuentra vacía.\n");
    }
    else
    {
        if(nav->inicio == nav->fin)
        {
            nav->inicio = NULL;
            nav->fin = NULL;
            free(nav->aux);
        }
        else
        {
            nav->inicio = nav->inicio->der;
            nav->inicio->izq = NULL;
            free(nav->aux);
        }
    }

    return;
}

/*
@brief Esta función borra todos los nodos que se encuentran en la lista 
       doble. Para hacerlo se utiliza la función borrarPrimero en un bucle
       do while, la condición es que se ejecute esa funcion mientras inicio
       y fin sean diferentes de NULL, esto significa que borra la lista 
       hasta que se encuentre vacía.
@author Alberto Parera Méndez en la clase de Guillermo Gómez
@date 16/10/2023
@param *nav es un apuntador de tipo refs, una caja con tres apuntadores: 
       inicio, aux y fin.
*/
extern void borrarTodos(refs *nav)
{
    char res;

    printf("\n¿Quieres borrar todos los nodos? ['s' | 'n']:\n");
    scanf(" %c", &res);
    if(res == 's')
    {
        do
        {
            borrarPrimero(nav);
        } while ((nav->inicio != NULL) && (nav->fin != NULL)); 
        imprimirListaDoble(*nav); 
    }

    return;
}

/*
@brief Esta función busca un alumno según su número de cuenta. Para hacerlo
       verifica que la lista no este vacía. Si no lo esta recorre la lista
       hasta que el apuntador aux sea NULL, es decir hasta el final de esta.
       Mientras se recorre la lista va comparando si el número de cuenta de 
       donde apunta aux es igual al proporcionado por el usuario, si lo es
       regresa esta dirección de memoria y si no lo es mueve aux al siguiente
       elemento de la lista.
@author Alberto Parera Méndez en la clase de Guillermo Gómez
@date 16/10/2023
@param nav es un apuntador de tipo refs, una caja con tres apuntadores: 
       inicio, aux y fin.
@param cuenta es un entero que proporcona el alumno en la función main, 
       este es el número de cuenta del alumno que se quiere encontrar.
@return es la direccion de memoria del apuntador aux, que esta apuntando
        al nodo del alumno con el número de cuenta que proprciono el usuario.
*/
extern nodo *buscarAlumno(refs nav, int cuenta)
{
    nav.aux = nav.inicio;

    if(nav.aux == NULL)
    {
        printf("\nLista vacíca\n.");
    }
    else
    {
        while(nav.aux != NULL)
        {
            if(cuenta == nav.aux->datos.cuenta)
            {
                return nav.aux; //un break; funcionaria igual
            }
            else
            {
                nav.aux = nav.aux->der;
            }
        }
    }

    return nav.aux;
}

/*
@brief Esta función borra el nodo borra de la lista doble. Para esto 
       verifica la posición de este nodo en la lista con cuatro condiciones:
       1) Si es el único nodo en la lista nada más manda a los apuntadores
          inicio y fin a NULL y libera el nodo borra.
       2) Si es el primer nodo manda a apuntar a inicio al siguiente nodo,
          después, hace que apunte a NULL y por ultimo libera el nodo borra.
       3) Si es el último nodo hace que el apuntador fin apunte al nodo a 
          la derecha, después lo manda a apuntar a NULL y por último libera
          el nodo borra.
       4) Si el nodo se encuentra en medio de la lista hace que el nodo a la
          izquierda del nodo borra apunte al nodo que se encuentra la derecha 
          de borra y que el nodo a la derecha apunte al de la izquierda. 
          Después libera el nodo borra.
@author Alberto Parera Méndez en la clase de Guillermo Gómez
@date 16/10/2023
@param *nav es un apuntador de tipo refs, una caja con tres apuntadores: 
       inicio, aux y fin.
@param *borra es el nodo que se encontró en la función buscarAlumno.
*/
extern void borrarNodoCuenta(refs *nav, nodo *borra)
{

    if(nav->inicio == nav->fin) //un solo nodo
    {
        nav->inicio = NULL;
        nav->fin = NULL;
        free(borra);
    }
    else
    {
        if(borra->izq == NULL) //primer nodo
        {
            nav->inicio = nav->inicio->der;
            nav->inicio->izq = NULL;
            free(borra);
        }
        else
        {
            if(borra->der == NULL) //ultimo nodo
            {
                nav->fin = nav->fin->izq;
                nav->fin->der = NULL;
                free(borra); 
            }
            else //nodo en medio
            {
                borra->izq->der = borra->der;
                borra->der->izq = borra->izq;
                free(borra);
            }
        }
    }

    return;
}
