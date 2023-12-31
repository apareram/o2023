/*
@file listaDoble.c
@brief Este es un ejemplo para construir una lista doblemente enlazada
       simple.
       A) Haga un programa que agregue datos de alumnos que están en un
          archivo de texto alumnos.txt y los integre a la lista en orden
          del apuntador der (derecha). Inserta conforme están capturados
          en el archivo.
          A.1) Imprima la lista 
       B) Haga una función que borre/atienda el nodo del inicio de la lista
          sin romper la integridad.
          B.1) Borre la lista completa.
          B.2) Haga un modulo/función que permita borrar un neodo que tenga
               el número de cuenta que indique el usuario.
       C) Cree una lista completa  que inserte los nodos en orden acendente
          de la cuenta único del usuario.
@author Alberto Parera Méndez en la clase de Guillermo Gómez
@date 12/10/2023
*/
#include "tiposDoble.h"

void insertarListaDoble(refs *nav, alum dat);
void imprimirListaDoble(refs nav);
void borrarPrimero(refs *nav);
void borrarTodos(refs *nav);
nodo *buscarAlumno(refs nav, int cuenta);
void borrarNodoCuenta(refs *nav, nodo *borra);

int main (int argc, char *argv[])
{
    FILE *fp;
    alum datos;
    refs navegador;
    int cuenta;
    nodo *nodoEncontrado;

    navegador.inicio = NULL;
    navegador.fin = NULL;
    navegador.aux = NULL;

    fp = fopen(argv[1], "r");
    if(fp == NULL)
    {
        printf("\nArchivo no disponible.\n");
        exit(1);
    }
    while(fscanf(fp, "%d\t %[^\t]%f\n", &datos.cuenta, datos.nombre, &datos.promedio) == 3)
    {
        insertarListaDoble(&navegador, datos);
    }
    fclose(fp);

    imprimirListaDoble(navegador);

    /*printf("\nSe borrara un nodo: \n");
    borrarPrimero(&navegador);
    imprimirListaDoble(navegador);   
    printf("\nSe borrara otro nodo: \n");
    borrarPrimero(&navegador);
    imprimirListaDoble(navegador);*/

    borrarTodos(&navegador);

    printf("\nDame un número de cuenta para buscar un alumno: ");
    scanf(" %d", &cuenta);
    nodoEncontrado = buscarAlumno(navegador, cuenta);
    if(nodoEncontrado == NULL)
    {
        printf("\nEl alumno no existe en el catálogo.\n");
    }
    else
    {
        printf("\nLa cuenta: %d ", cuenta);
        printf("pertenece al alumno: %s ", nodoEncontrado->datos.nombre);
        printf("que tiene pormedio: %f ", nodoEncontrado->datos.promedio);
        printf("y tiene dirección de memoria: %p\n", nodoEncontrado);
    }

    printf("\nDame un número de cuenta para borrar ese nodo de un alumno: ");
    scanf(" %d", &cuenta);
    nodoEncontrado = buscarAlumno(navegador, cuenta);
    if(nodoEncontrado == NULL)
    {
        printf("\nEl alumno no existe en el catálogo.\n");
    }
    else
    {
        borrarNodoCuenta(&navegador, nodoEncontrado);
        imprimirListaDoble(navegador);
    }

    return 0;
}