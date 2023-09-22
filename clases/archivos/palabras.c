/*
@file palabras.c
@brief Este programa permite escribir una frase en el archivo frases.txt.
       Una vez que la frase quedó escrita, el programa cuenta cuántas
       palabras fueron escritas.
       A) Permita que el usuario ingrese el nombre del archivo desde la
          linea de comandos.
          $./palabras.exe miFrase.txt
@autor Alberto Parera Méndez en la clase de Guillermo Gómez
@fecha 07/09/2023
*/

#include "defTipos.h"

int contarPalabras(char archivo[]);

int main(int argc, char *argv[])
{
    FILE *fp;
    char frase[250];
    int numPalabras;
    
    fp = fopen(argv[1], "w");
    if(fp == NULL)
    {
        printf("\nArchivo no disponible\n");
        exit(1);
    }
    printf("\nDame la frase: \n");
    scanf("%[^\n]", frase);
    fprintf(fp, "%s", frase);
    fclose(fp);

    numPalabras = contarPalabras(argv[1]);
    printf("\nSu frase contiene %i palabras.\n", numPalabras);

    return 0;
}