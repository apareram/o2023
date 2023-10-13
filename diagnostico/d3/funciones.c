
#include "typedef.h"

extern float insertarListaDoble(char nomArch[], refs *nav)
{
    FILE *fp;
    nodo *nuevo;
    tipoMascota pet;
    float prom = 0.0;
    float sum = 0.0;
    float i = 0.0;

    fp = fopen(nomArch, "r");
    if(fp == NULL)
    {
        printf("\nArchivo no disponible.\n");
        exit(1);
    }

    nuevo = (nodo *)malloc(sizeof(nodo));
    if(nuevo == NULL)
    {
        printf("\nNo hay memoria disponible.\n");
        exit(1);
    }
    nuevo->izq = NULL;
    nuevo->der = NULL;

    while(fscanf(fp, "%[^\t] %f\t %i\n", nuevo->datos.raza, &nuevo->datos.peso, &nuevo->datos.edad) == 3)
    {
        if((nav->inicio == NULL) && (nav->fin == NULL))
        {
            nav->inicio = nuevo;
            nav->fin = nuevo;
            sum = nuevo->datos.edad;
        }
        else
        {
            nuevo->izq = nav->fin;
            nav->fin->der = nuevo;
            nav->fin = nuevo;
            sum +=  nuevo->datos.edad;
        }
        i++;
    }
    fclose(fp);

    prom = sum/i;

    return prom;
}

extern void imprimirListaDoble(refs nav)
{
    nav.aux = nav.inicio;
    if (nav.inicio == NULL && nav.fin == NULL) 
    {
        printf("\nLista vacía.\n");
    }
    else
    {
        printf("\nRAZA\tPESO\tEDAD\n");
        while (nav.aux != NULL) 
        {
            printf("%s\t%f\t%i\n", nav.aux->datos.raza, nav.aux->datos.peso, nav.aux->datos.edad);
            nav.aux = nav.aux->der;
        }
    }

    return;
}
/*
extern void imprimirCanesPorRazas(tipoMascota *lista) {
    printf("Canes cuyas razas inician con las letras 'a' a 'h':\n");
    nodo *actual = lista->inicio;

    while (actual != NULL) {
        char primera_letra = tolower(actual->nombre[0]);

        
        if (primera_letra >= 'a' && primera_letra <= 'h') {
            printf("Nombre: %s, Edad: %d\n", actual->nombre, actual->edad);
        }

        actual = actual->next;
    }
}*/