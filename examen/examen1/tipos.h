#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct autos 
{
    char marca[20];
    char modelo[20];
    char placa[20];
    int ano;
};

typedef struct autos tipoAutos;

struct elemento
{
    tipoAutos autos;
    struct elemento *next;
};

typedef struct elemento nodo;