/*
@file banco.c
@brief 
@author 
@date 
*/

#include "tipos.h"

nodo *leerDatos(char nomArch[]);
void imprimirLista(nodo *pt);
void guardarenTexto(nodo *pt);
void reporteVerificacion(nodo *aux);
void recorrerNodos(nodo *aux2);

int main(int arc, char *argv[])
{   
    nodo* inicio;
    int opmenu = 1;
    inicio = NULL;

    printf("\n\nBienvenido a este programa, a continuación se le mostraran las opciones del menú.\n\n");
    printf("Ingrese la tecla <enter> para continuar\n\n");
    getchar();
    while((opmenu == 1) || (opmenu == 2))
    {
        imprimirLista(inicio);
        printf("\n\n------------------------------------Menú------------------------------------\n\n");
        printf("\nEscribe [1] si quieres guardar los datos en el archivo de texto en una lista LIFO.\n");
        printf("\nEscribe [2] si quieres imprimir en pantalla en contenido de la lista LIFO.\n");
        printf("\nEscribe [3] si quieres finalizar el programa.\n\n");
        scanf("%d", &opmenu);
        if(opmenu == 1)
        {
            inicio = leerDatos(argv[1]);
        }
        if(opmenu == 2)
        {
            imprimirLista(inicio);
        }
    }
    
    inicio = leerDatos(argv[1]);
    imprimirLista(inicio);
    /*
    guardarenTexto(inicio);
    reporteVerificacion(inicio);
    recorrerNodos(inicio);
    */
    return 0;
}