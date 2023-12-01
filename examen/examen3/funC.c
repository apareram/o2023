/*
@file funciones.c
@brief Este archivo contiene las funciones que son llamadas desde appIMC.c
@authors Alberto Parera, Diego Tovar y Ariadna Pedraza
@date 30/2023
*/

#include "defGTK.h"

/*
@brief Esta función básicamente implementa la logica de inserción en un arbol binario de busqueda, 
       donde se decide si un nuevo nodo debe colocarse en el subárbol izquierdo o derecho en función del IMC calculado.
@author Alberto Parera, Diego Tovar y Ariadna Pedraza 
@date 30/11/2023
@param char inNom[]: Un arreglo de caracteres que representa el nombre del nuevo nodo a insertar en el arbol.
@param float inPeso: Un número decimal que representa el peso del nuevo nodo a insertar en el árbol.
@return
*/


arbolIMC *insertarYcalcular(char inNom[], float inPeso, float inEstatura, arbolIMC *raiz)
{
    arbolIMC *nodo, *nuevoNodo;
    nodo = raiz;

    nuevoNodo = (arbolIMC*)malloc(sizeof(arbolIMC));

    if (nodo == NULL) 
    {
        strcpy(nuevoNodo->nombre, inNom);
        nuevoNodo->peso = inPeso;
        nuevoNodo->estatura = inEstatura;
        nuevoNodo->IMC = inPeso / (inEstatura * inEstatura);
        nuevoNodo->izq = nuevoNodo->der = NULL;

        return nuevoNodo;
    }

    if (inPeso / (inEstatura * inEstatura) < nodo->IMC) 
    {
        nodo->izq = insertarYcalcular(inNom, inPeso, inEstatura, nodo->izq);
    } 
    else if (inPeso / (inEstatura * inEstatura) > nodo->IMC) 
    {
        nodo->der = insertarYcalcular( inNom, inPeso, inEstatura,nodo->der);
    }

    return nodo;
}

/*
@brief
@author Alberto Parera, Diego Tovar y Ariadna Pedraza 
@date 30/11/2023
@param 
@param 
*/


void imprimirIMC(refsApp *refs) 
{       

    char cadDiag[200];
    char cadFInal[200];

    if (refs->raiz->IMC > 25) 
    {
        strcpy(cadDiag, "Elcpaciente es un sobrepeso");

    } 
    if (refs->raiz->IMC > 30) 
    {
        strcpy(cadDiag, "El paciente es un obeso");

    }
    if ((refs->raiz->IMC < 25) && (refs->raiz->IMC > 18.5)) 
    {
        strcpy(cadDiag, "El paciente es un normal.");

    }
    if (refs->raiz->IMC < 25) 
    {
        strcpy(cadDiag, "El paciente es un infrapeso");

    }

    sprintf(refs->diag, "Tiene de IMC: %.2f. ", refs->raiz->IMC);

    strcat(refs->diag, cadDiag);

    return;
}

/*
@brief
@author Alberto Parera, Diego Tovar y Ariadna Pedraza 
@date 30/11/2023
@param 
@param 
*/

void imprimirEnOrden(arbolIMC *raiz) 
{
    if (raiz != NULL) 
    {
        imprimirEnOrden(raiz->izq);
        printf("%s que pesa %.2f kgs, mide %.2f mts y tiene un IMC de %.2f\n", raiz->nombre, raiz->peso, raiz->estatura, raiz->IMC);
        imprimirEnOrden(raiz->der);
    }
}