#include "tiposGTK.h"

extern void insertarCola(rep libro, refsApp *refs)
{
    if((refs->inicio == NULL) && (refs->fin == NULL))
    {
        libro->der = libro;
        libro->izq = libro;
        refs->inicio = libro;
        refs->fin = libro;
    }
    else
    {
        libro->izq = refs->fin;
        libro->der = refs->inicio;
        refs->fin->der = libro;
        refs->inicio->izq = libro;
        refs->fin = libro;
    }

    return;
}

extern void imprimirListaDoble(refsApp refs)
{
    refs.aux = refs.inicio;

    if((refs.inicio == NULL) && (refs.fin == NULL))
    {
        printf("\nNo puedo imprimir una lista vacía.\n");
    }
    else
    {
        do
       {
            printf("\nTítulo del libro: %s", refs.aux->titulo);
            printf("\tNúmero de secciones: %d\n", refs.aux->numSeccs);
            refs.aux = refs.aux->der;
       }while(refs.aux != refs.inicio); 
    }

    return;
}