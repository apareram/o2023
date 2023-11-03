#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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