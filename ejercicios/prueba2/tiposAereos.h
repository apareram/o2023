#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pasajero 
     {
        char nombre[40];
        int zona;
     };
typedef struct pasajero pasa;

struct elemento
    {
        pasa datos;
        struct elemento *izq, *der;
        
    };
typedef struct elemento nodo;

struct referencias
    {
        nodo *inicio, *fin, *aux;
    };
typedef struct referencias refs;

struct navegador 
     {
        char nombre[40];
        int zona;
        struct nav *refInicio, *aux;
     };
typedef struct navegador nav;