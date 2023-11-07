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
void insertarListaDoble(referencias *nav, entero dat);
void insertarListaOrdenada(entero dat, referencias *filaO);
void imprimirListaDoble (referencias filaO);
nodo *buscarNumero(referencias filaO, int numero);
void guardarArchText (referencias filaO);
void crearArbol(char nomArch[], nodo **raiz);
nodo *buscarDirecto(int busca, nodo *aux);
void recorrer(nodo *aux);
void bubbleSort(int arr[], int size);
void agregarArch(int arr[], int size);
void quickSort(int arr[], int n);
int busquedaBinariaLineal (int x, int arr[], int n);
extern int busquedaLineal(int x, int arr[], int n);

int main(int argc, char *argv[])
{
   FILE *fp;
   nodo *raiz = NULL, *resBusqueda, *nodoEncontrado;
   int *enteros, tam, numBusq, num;
   double tiempo;
   clock_t tInicial, tFinal;

   entero datos;
   referencias navegador, listaO;

   navegador.inicio = NULL;
   navegador.fin = NULL;
   navegador.actual = NULL;

   listaO.inicio = NULL;
   listaO.fin = NULL;
   listaO.actual = NULL;

   tam = calcularTam(argv[1]);
   enteros = (int *)malloc(tam * sizeof(int));
   if(enteros == NULL)
   {
      printf("\nNo hay memoria dispible.\n");
      exit(1);
   }

   colocarEnteros(argv[1], enteros);
   printf("\nNuúmeros desordenados:\n");
//   imprimirArreglo(enteros, tam);

   fp = fopen(argv[1], "r");
   printf("\nOrdenamiento con un incerción:\n");
   //tiempo inicial
   tInicial = clock();
   if(fp == NULL)
   {
      printf("\nArchivo no disponible.\n");
      exit (1);
   }
   while(fscanf(fp, "%d\n", &datos.numero) == 1)
   {
      insertarListaDoble(&navegador, datos);
      insertarListaOrdenada(datos, &listaO);
   }
   fclose(fp);
   guardarArchText(listaO);
  // imprimirListaDoble(listaO);
   //tiempo final
   tFinal = clock();
   tiempo = (double)(tFinal - tInicial) / CLOCKS_PER_SEC;
   printf("\nLa función insertarListaOrdenada tardó %.4f segundos en ejecutarse.\n", tiempo);

   printf("\n\nDame el número que quieres buscar: \n");
   scanf("%d", &num);

   nodoEncontrado = buscarNumero(listaO, num);
   if(nodoEncontrado == NULL)
   {
      printf("\nEl número no existe en el catálogo.\n\n");
   }
   else
   {
      printf("\nEl número: %d está en la dirección de memoria: %p\n\n", num, nodoEncontrado);
   }

   remove("ordenados.txt"); 

   printf("\nOrdenamiento con un Árbol:\n");
   //tiempo inicial
   tInicial = clock();
   crearArbol(argv[1], &raiz);
//   recorrer(raiz);
   //tiempo final
   tFinal = clock();
   tiempo = (double)(tFinal - tInicial) / CLOCKS_PER_SEC;
   printf("\nLa función crearArbol y recorrer tardó %.4f segundos en ejecutarse.\n", tiempo);
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

   printf("\nOrdenamiento Blubblesort\n");
   //tiempo inicial
   tInicial = clock();
   resBusqueda = buscarDirecto(numBusq, raiz);
   bubbleSort(enteros, tam);
   tFinal = clock();
   tiempo = (double)(tFinal - tInicial) / CLOCKS_PER_SEC;
   printf("La función bubbleSort se tardó %.4f segundos en ejecutarse.\n", tiempo);
   //tiempo final
  // imprimirArreglo(enteros, tam);
   agregarArch(enteros, tam);

   colocarEnteros(argv[1], enteros);

   printf("\nOrdenamiento QuickSort:\n");
   //tiempo inicial
   tInicial = clock();
   quickSort(enteros, tam);
   tFinal = clock();
   tiempo = (double)(tFinal - tInicial) / CLOCKS_PER_SEC;
   printf("La función quickSort se tardó %.4f segundos en ejecutarse.\n", tiempo);
   //tiempo final
   //imprimirArreglo(enteros, tam);
   //busquedaBinariaLineal (int x, int arr[], int n);
   // int busquedaLineal(int x, int arr[], int n);

   return 0;
}
