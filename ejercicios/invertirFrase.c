/*
@file invertirFrase.c
@brief Se tiene una frase guardada en un archivo de texto frase.txt; 
       la frase dice:
       La educación no es algo que tú puedes terminar
       
       Haga un programa en C que utilice Listas Simples Lineales y con 
       la ayuda de estas, invierta la frase; la frase debe de quedar así:
       terminar puedes tú que algo es no educación La
       
       Imprima en pantalla la frase invertida con la ayuda de Listas 
       Lineales Simples; guarde la frase invertida en el archivo de 
       salida invertida.txt.
@author Alberto Parera Méndez
@date 25/09/2023
*/

#include "tipos.h"

void guardarInvertida(nodo *pt);
nodo *copiarenLIFO(char nomarch[]);

int main(int argc, char *argv[])
{
    nodo *inicio;
    char nom[40];
    
    inicio = NULL;

    inicio = copiarenLIFO(argv[1]);

    guardarInvertida(inicio);
    
    return 0;
}