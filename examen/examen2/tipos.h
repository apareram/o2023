#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct fruteria 
     {
        char fruta[40];
        float precio;
        float inventario;
     };
typedef struct fruteria frut;

struct elemento
    {
        frut inventario;
        struct elemento *izq, *der;
        
    };
typedef struct elemento nodo;

struct referencias
    {
        nodo *inicio, *fin, *aux;
    };
typedef struct referencias refs;