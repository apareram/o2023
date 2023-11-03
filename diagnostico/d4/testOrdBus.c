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

int calcularTam(char nomArch[]);
void colocarEnteros(char nomArch[], int arr[]);
void imprimirArreglo(int arr[], int size);
void bubbleSort(int arr[], int size);
void colocarEnteros(char nomArch[], int arr[]);
void quickSort(int arr[], int size);
void crearArbol(char nomArch[], nodo **raiz);
nodo *buscarDirecto(int busca, nodo *aux);
extern void recorrer(nodo *aux);

int main(int argc, char *argv[])
{
   nodo *raiz = NULL, *resBusqueda;
   int *enteros, tam, numBusq;
   double tiempo;
   clock_t tInicial, tFinal;

   remove("ordenados.txt"); 


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
   printf("\nOrdenamiento con un Árbol:\n");
   //tiempo inicial
   tInicial = clock();
   crearArbol(argv[1], &raiz);
   recorrer(raiz);
   //tiempo final
   tFinal = clock();
   tiempo = (double)(tFinal - tInicial) / CLOCKS_PER_SEC;
   printf("La función crearArbol y recorrer tardó %.4f segundos en ejecutarse.\n", tiempo);
   printf("\nDame el número que deseas buscar por búsqueda directa: \n");
   scanf(" %d", &numBusq);
   //tiempo inicial
   tInicial = clock();
   resBusqueda = buscarDirecto(numBusq, raiz);
   if(resBusqueda == NULL)
   {
      printf("\nBusqueda sin éxito, el dato no está en el árbol.\n");
   }
   else
   {
      printf("\nEn la dirección %p está %d.\n", resBusqueda, resBusqueda->dato);
   }
   tFinal = clock();
   tiempo = (double)(tFinal - tInicial) / CLOCKS_PER_SEC;
   printf("La función buscarDirecto se tardó %.4f segundos en ejecutarse.\n", tiempo);

   //tiempo final

   /*
   printf("\nOrdenamiento Blubblesort\n");
   //tiempo inicial
   tInicial = clock();
   resBusqueda = buscarDirecto(numBusq, raiz);
   bubbleSort(enteros, tam);
   tFinal = clock();
   tiempo = (double)(tFinal - tInicial) / CLOCKS_PER_SEC;
   printf("La función bubbleSort se tardó %.4f segundos en ejecutarse.\n", tiempo);
   //tiempo final
   imprimirArreglo(enteros, tam);

   colocarEnteros(argv[1], enteros);
   printf("\nOrdenamiento QuickSort:\n");
   //tiempo inicial
   tInicial = clock();
   quickSort(enteros, tam);
   tFinal = clock();
   tiempo = (double)(tFinal - tInicial) / CLOCKS_PER_SEC;
   printf("La función quickSort se tardó %.4f segundos en ejecutarse.\n", tiempo);
   //tiempo final
   imprimirArreglo(enteros, tam);
   */
   return 0;
}