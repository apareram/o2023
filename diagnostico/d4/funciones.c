#include "defTipos.h"

extern void colocarEnteros(char nomArch, int arr[])
{
    int i = 0, numero;
    FILE *fp;

    fp = fopen(nomArch, "r");
    if(fp == NULL)
    {
        printf("\nArchivo no disponible\n");
        exit(1);
    }

    while(fscanf(fp, "%d", &numero) == 1)
    {
        arr[i] = numero;
        i++;
    }
    fclose(fp);

    return;
}

extern int calcularTam(char nomArch[])
{
    FILE *fp;
    int tam = 0, numero = 0;

    fp = fopen(nomArch, "r");
    if(fp == NULL)
    {
        printf("\nArchivo no disponible\n");
        exit(1);
    }
    while(fscanf(fp, "%d", &numero) == 1)
    {
        tam++;
    }
    fclose(fp);

    return tam;
}

extern void imprimirArreglo(int arr[], int size)
{
    int i;
    printf("\nLos enteros en el arreglo están ahora así: \n");
    for(i = 0; i < size; i++)
    {
        printf("\n %d\n", arr[i]);
    }

    return;
}
