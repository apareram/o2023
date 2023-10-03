#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct elemento 
{
    int prioridad;
    char nombre[80];
    struct elemento *next;
};

typedef struct elemento nodo;