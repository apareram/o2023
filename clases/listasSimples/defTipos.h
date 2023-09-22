#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct elemento
{
    char palabra[40];
    struct elemento *next;
};

typedef struct elemento nodo;