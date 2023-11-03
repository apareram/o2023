#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct enteros
{
  int numero;
};
typedef struct enteros entero;

struct elemento
{
    int dato;
    struct elemento *izq, *der;
};
typedef struct elemento nodo;

struct posiciones
{
    nodo *inicio, *fin, *actual;
};
typedef struct posiciones referencias;