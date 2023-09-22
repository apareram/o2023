#include "defTipos.h"
/*
@brief Esta función cuanta las palabras que hay en un archivo de texto y 
       devuelve el número de palabras.
*/
extern int contarPalabras(char archivo[])
{
    int numPalabras = 0;
    FILE *fp;
    char palabra[50];

    fp = fopen(archivo, "r");
    if(fp == NULL)
    {
        printf("\nArchivo no disponible\n");
        exit(1);
    }
    while(fscanf(fp,"%s", palabra) == 1)
    {
        numPalabras += 1;
    }
    fclose(fp);

    return numPalabras;
}