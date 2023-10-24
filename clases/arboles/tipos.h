#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct elemento
    {
        int num;
        struct elemnto *izq, *der;
    };
typedef struct elemento nodo;

