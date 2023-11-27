#include "tiposGTK.h"

void instertarTodo(char tituloLibro[], int numeroSeccion, refsApp *refs)
{
    int cont = 1;
    rep *newLibro;

    newLibro = (rep *)malloc(sizeof(rep));
    if (newLibro == NULL) 
    {
        printf("\nNo hay memoria suficiente\n");
        return;
    }

    newLibro->inicio = NULL;
    newLibro->fin = NULL;
    newLibro->aux = NULL;

    strcpy(newLibro->titulo, tituloLibro);
    newLibro->numSeccs = numeroSeccion;

    while(cont <= numeroSeccion)
    {
        secc *newSecc;
        newSecc = (secc *)malloc(sizeof(secc));

        hoja *newPag;
        newPag = (hoja *)malloc(sizeof(hoja));

        newSecc->izq = NULL;
        newSecc->der = NULL;
        newSecc->primPag = NULL;
        newSecc->ultPag = NULL;

        newSecc->numSecc = cont;

        newPag->next = NULL;

        newSecc->primPag = newPag;
        newSecc->ultPag = newPag;

        if((newLibro->inicio == NULL) && (newLibro->fin == NULL))
        {
            newLibro->inicio = newSecc;
            newLibro->fin = newSecc;
            newLibro->aux = newSecc;
        }
        else
        {
            newSecc->izq = newLibro->fin;
            newLibro->fin->der = newSecc;
            newLibro->fin = newSecc;
        }

        cont++;
    }

    if((refs->inicio == NULL) && ( refs->fin == NULL))
    {
        newLibro->der = newLibro;
        newLibro->izq = newLibro;
        refs->inicio = newLibro;
        refs->fin = newLibro;
    }
    else
    {
        newLibro->izq = refs->fin;
        newLibro->der = refs->inicio;
        refs->fin->der = newLibro;
        refs->inicio->izq = newLibro;
        refs->fin = newLibro;
    }

    return;
}

void imprimirLibro(rep refs)
{
    refs.aux = refs.inicio;

    while(refs.aux != NULL)
    {
        printf("\nNombre de sección: %s\t", refs.aux->titSeccion);
        printf("Número de sección: %d\n", refs.aux->numSecc);
        refs.aux = refs.aux->der;
    }
    if((refs.inicio == NULL) && (refs.fin == NULL))
    {
        printf("\nLista vacía.\n");
    }

    return;
}

extern void imprimirRepisa(refsApp refs)
{
    refs.aux = refs.inicio;

    if((refs.inicio == NULL) && (refs.fin == NULL))
    {
        printf("\nNo puedo imprimir una repisa vacía.\n");
    }
    else
    {
        do
       {
            printf("\nTítulo del libro: %s", refs.aux->titulo);
            printf("\tNúmero de secciones: %d\n", refs.aux->numSeccs);
            imprimirLibro(*(refs.aux));
            refs.aux = refs.aux->der;
       }while(refs.aux != refs.inicio); 
    }

    return;
}
