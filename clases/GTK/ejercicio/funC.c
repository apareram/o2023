#include "defTiposGTK.h"

void insertarCola(tipoMascota dat1, refsApp *pMiApp)
{
    nodo *nuevo;
    
    nuevo = (nodo *)malloc(sizeof(nodo));
    if(nuevo == NULL)
    {
        printf("\nNo hay memoria disponible\n");
        exit(1);
    }
    nuevo->datos = dat1;
    if((pMiApp->inicio == NULL) && (pMiApp->fin == NULL))
    {
        nuevo->der = nuevo;
        nuevo->izq = nuevo;
        pMiApp->inicio = nuevo;
        pMiApp->fin = nuevo;
    }
    else{
        nuevo->izq = pMiApp->fin;
        nuevo->der = pMiApp->inicio;
        pMiApp->fin->der = nuevo;
        pMiApp->inicio->izq = nuevo;
        pMiApp->fin = nuevo;
    }

    return;
}

extern void imprimirListaDobleCirc(refsApp pMiApp)
{
    pMiApp.aux = pMiApp.inicio;

    if((pMiApp.inicio == NULL) && (pMiApp.fin == NULL))
    {
        printf("\nNo puedo imprimir una lista vacía.\n");
    }
    else
    {
        do
       {
            printf("Cliente: %d\n", pMiApp.aux->datos.cliente);
            printf("Raza: %s\t", pMiApp.aux->datos.raza);
            printf("Peso: %f\t", pMiApp.aux->datos.peso);
            pMiApp.aux = pMiApp.aux->der;
       }while(pMiApp.aux != pMiApp.inicio); 
    }

    return;
}

extern void crearListaDoble(char nomArch[], refsApp *pMiAPP)
{
    FILE *fp;
    tipoMascota datos;

    fp = fopen(nomArch, "r");
    if(fp == NULL)
    {
        printf("\nArchivo no disponible.\n");
        exit(1);
    }
    while(fscanf(fp, " %[^\t]%f\t%d\n", datos.raza, &datos.peso, &datos.cliente) == 3)
    {
        insertarCola(datos, pMiAPP);
    }
    fclose(fp);

    return;
}
