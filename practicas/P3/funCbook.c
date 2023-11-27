#include "tiposGTK.h"

extern void insertarCola(rep *libro, refsApp *refs)
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

extern void insertarListaDoble(refsApp *refs, secc *secci)
{
    secci->izq = NULL;
    secci->der = NULL;

    if((refs->fin->inicio == NULL) && (refs->fin->fin == NULL))
    {
        refs->fin->inicio = secci;
        refs->fin->fin = secci;
    }
    else
    {
        secci->izq = refs->fin->fin;
        refs->fin->fin->der = secci;
        refs->fin->fin = secci;
    }
    printf("prueba1");
    return;
}

extern void imprimirListaDobleSecc(refsApp refs)
{
    refs.fin->aux = refs.fin->inicio;

    while(refs.fin->aux != NULL)
    {
        printf("\nNombre de sección: %s\t", refs.fin->aux->titSeccion);
        printf("Número de sección: %d\n", refs.fin->aux->numSecc);
        refs.fin->aux = refs.fin->aux->der;
    }
    if((refs.fin->inicio == NULL) && (refs.fin->fin == NULL))
    {
        printf("\nLista vacía.\n");
    }

    return;
}