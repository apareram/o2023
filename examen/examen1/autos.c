/*
@file autos.c
@brief Este genera informes de autos que se desean verificar.
       1) El programa lee los datos que se encuetran en un archivo de 
          texto ingresando el nombre desde la terminal y coloca los datos
          en una lista LIFO.
        2) El programa imprime los datos de la lista LIFO en panatalla.
        3) El programa hace un reporte de cuando se deben verificar los 
           coches dependiendo de la terminación de la placa y lo imprime
           en pantalla.
        4) El programa le pregunta al usuario si desea recorrer los nodos
           y los imprime en pantalla.
@author Alberto Parera Méndez en el examenm de Guillermo Gómez
@date 29/09/2023
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

    inicio = NULL;
    inicio = leerDatos(argv[1]);
    imprimirLista(inicio);
    guardarenTexto(inicio);
    reporteVerificacion(inicio);
    recorrerNodos(inicio);

    return 0;
}