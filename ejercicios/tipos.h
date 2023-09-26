#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct elemento
{
    char palabra[40];
    struct elemento *next;
};

typedef struct elemento nodo;

struct alumno 
     {
        char nombre[40];
        float calCalc;
        float calFis;
        float calProg;
     };

typedef struct alumno tipoAlumno;

struct elemento2
{
    tipoAlumno alumno[40];
    struct elemento *siguiente;
};

typedef struct elemento2 nodo1;
