#include <gtk-2.0/gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct arbol 
     {
        char nombre[100];
        float peso;
        float estatura;
        float IMC;
        struct arbol *izq, *der;
     };
typedef struct arbol arbolIMC;

struct appGTK
{
    arbolIMC *raiz;
    char diag[100];
    GtkWidget *nombre, *peso, *estatura, *IMC;
    GtkWidget *diagnosticosLbl;
};
typedef struct appGTK refsApp;