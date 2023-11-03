#include "defTipos.h"

/*
 @file testOrdBus.c
 @brief El objetivo de este programa es conocer y evaluar los distintos métodos de ordenamiento
        y búsqueda.
        A) A partir de n datos enteros contenidos en un archivo de texto, y con el uso de memoria
           dinámica, tenemos que generar.
           A.1) Tener un archivo de enteros sin repeticiones que estén ordenados.
           A.2) Tener esos mismos enteros sin repeticiones en un arreglo.
        B) El programa debe manejar un archivo de entrada que contiene enteros con la línea de comandos.
        C) Calcule el tamaño que debe tener el arreglo dinámico. Para ello, calcule cuantos enteros tiene
           el archivo.
 */

int calcularTam(char nomArch);
void colocarEnteros(char nomArch, int arr[]);
void imprimirArreglo(int arr[], int size);
void bubbleSort(int arr[], int size);
void colocarEnteros(char nomArch, int arr[]);
void quickSort(int arr[], int size);

int main(int argc, char *argv[])
{
   int *enteros, tam;

   tam = calcularTam(argv[1]);
   enteros = (int *)malloc(tam * sizeof(int));
   if(enteros == NULL)
   {
      printf("\nNo hay memoria dispible.\n");
      exit(1);
   }
   colocarEnteros(argv[1], enteros);
   printf("\nNuúmeros desordenados:\n");
   imprimirArreglo(enteros, tam);
   printf("\nOrdenamiento Blubblesort\n");
   //tiempo inicial
   bubbleSort(enteros, tam);
   //tiempo final
   imprimirArreglo(enteros, tam);

   colocarEnteros(argv[1], enteros);
   printf("\nOrdenamiento QuickSort:\n");
   //tiempo inicial
   quickSort(enteros, tam);
   //tiempo final
   imprimirArreglo(enteros, tam);

   return 0;
}