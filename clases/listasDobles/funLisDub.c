#include "tiposDoble.h"

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
