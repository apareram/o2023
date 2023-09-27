/*
@file funciones.c
@brief Este  archivo contiene las funciones que son llamadas desde
       invertirFrases.c y alumnos.c. 
@author Alberto Parera Méndez
@date 25/09/2023
*/

#include "tipos.h"

/*
@brief Esta función agrega un nodo al inicio de la lista con la operación
       en invertirFrases.c.
@author Alberto Parera Méndez en la clase de Guillermo Gómez
@date 21/09/2023
@param pal[] y es una cadena de chars.
@param *pt es un apuntador del tipo nodo.
@return *pt es un apiuntador de tipo nodo que devuelve el nuevo inicio de
        la lista.
*/
extern nodo *push(char pal[], nodo *pt)
{
    nodo *nuevo;

    nuevo = (nodo *)malloc(sizeof(nodo));
    if(nuevo == NULL)
    {
        printf("\nNo hay memoria disponible.\n");
        exit(1);
    }
    strcpy(nuevo->palabra, pal);
    nuevo->next = pt;
    pt = nuevo;

    return pt;
}

/*
@brief Esta función copia lo que se encuentra en el acrhivo de texto y lo
       coloca en una lista LIFO.
@author Alberto Parera Méndez 
@date 25/09/2023
@param archNom[] es una cadena de chars qu contiene el nombre del archivo de
       texto.
@param *pt es un apuntador del tipo nodo.
@return *pt es un apiuntador de tipo nodo que devuelve el nuevo inicio de
        la lista.
*/
extern nodo *copiarenLIFO(char nomarch[])
{
    nodo *pt;
    char pal[40];
    FILE *fp;

    fp = fopen(nomarch, "r");
    if(fp == NULL)
    {
        printf("\nArchivo no disponible\n");
        exit(1);
    }

    pt = NULL;
    
    while(fscanf(fp, "%s", pal) == 1)
    {
        pt = push(pal, pt);
    }
    fclose(fp);

    return pt;
}

/*
@brief Esta crea un archivo txt a partir de lo que se encuentra en una 
       lista LIFO.
@author Alberto Parera Méndez 
@date 25/09/2023
@param *pt es un apuntador del tipo nodo.
*/
extern void guardarInvertida(nodo *pt)
{
    FILE *fp;

    fp = fopen("invertida.txt", "w");
    if(pt != NULL)
    {
        while(pt != NULL)
        {
            fprintf(fp, "%s\t", pt->palabra);
            pt = pt->next;
        }
    }
    else
    {
        printf("\nLista vacía\n");
    }
    fclose(fp);

    return;
}

/*
@brief Esta función agrega un nodo al inicio del struct alumnos con la 
       operación en alumnos.c.
@author Alberto Parera Méndez
@date 26/09/2023
@param alumno es una estructura de tipo alumno.
@param *pt es un apuntador del tipo nodo1.
@return *pt es un apiuntador de tipo nodo1 que devuelve el nuevo inicio de
        la lista.
*/
extern nodo1 *push2(tipoAlumno alumno, nodo1 *pt)
{
    nodo1 *nuevo1;

    nuevo1 = (nodo1 *)malloc(sizeof(nodo1));
    if(nuevo1 == NULL)
    {
        printf("\nNo hay memoria disponible.\n");
        exit(1);
    }
    nuevo1->alumno = alumno;
    nuevo1->siguiente = pt;
    pt = nuevo1;

    return pt;
}

/*
@brief Esta función copia lo que se encuentra en el acrhivo de texto y lo
       coloca en una lista LIFO.
@author Alberto Parera Méndez 
@date 26/09/2023
@param archNom[] es una cadena que contiene el nombre del archivo de
       texto.
@param *pt es un apuntador del tipo nodo1.
@return *pt es un apuntador de tipo nodo1 que devuelve el nuevo inicio de
        la lista.
*/
extern nodo1 *leerDatos(char nomArch[])
{
    FILE *fp;
    nodo1 *pt;
    tipoAlumno alumno;

    fp = fopen(nomArch, "r");
    if(fp == NULL)
    {
        printf("\nArchivo no disponible\n");
        exit(1);
    }

    pt = NULL;
    
    while(fscanf(fp, "%s\t%f\t%f\t%f\n", alumno.nombre, &alumno.calCalc, &alumno.calFis, &alumno.calProg) == 4)
    {
        pt = push2(alumno, pt);
    }
    fclose(fp);

    return pt;
}

/*
@brief Esta función imprime en pantalla lo que se encuentra en la lista 
       LIFO.
@author Alberto Parera Méndez 
@date 26/09/2023
@param *pt es un apuntador del tipo nodo1.
*/
extern void imprimirLista(nodo1 *pt)
{
    printf("\nComprobando que la lista está completa:\n");
    if(pt != NULL)
    {
        while(pt != NULL)
        {
            printf("%s\t%f\t%f\t%f\n", pt->alumno.nombre, pt->alumno.calCalc, pt->alumno.calFis, pt->alumno.calProg);
            pt = pt->siguiente;
        }
    }
    else
    {
        printf("\nLista vacía\n");
    }
    return;
}

/*
@brief Esta función hace varias cosas:
       1) Saca el promedio de las calificaciones que se encuentran en la
          lista LIFO y las imprime en pantalla (mientras sean mayor o igual
          a lo ingresado en la lista de comandos).
       2) Crea un archivo de texto y guarda ahí los promedios que sean mayor 
          o igual a lo ingresado en la lista de comandos.
@author Alberto Parera Méndez 
@date 26/09/2023
@param *pt es un apuntador del tipo nodo1.
@param prom es un flotante, el número que se ingreso en la linea de comandos.
*/
extern void imprimirPromedios(nodo1 *pt, float prom)
{
    float promedio;
    FILE *fp;

    fp = fopen("promedios.txt", "w");

    if(pt != NULL)
    {
        printf("\nPromedio de los alumnos:\n");
        while(pt != NULL)
        {
            promedio = (pt->alumno.calCalc + pt->alumno.calFis + pt->alumno.calProg)/3.0;
            if(promedio >= prom)
            {
                printf("%s\t%f\n", pt->alumno.nombre, promedio);
                fprintf(fp, "%s\t%f\n", pt->alumno.nombre, promedio);
            }
            else
            {
                printf("\nNo hay más alumnos con un promedio igual o mayor al ingresado.\n");
            }
            pt = pt->siguiente;
        }
    }
    else
    {
        printf("\nLista vacía\n");
    }

    fclose(fp);

    return;
}