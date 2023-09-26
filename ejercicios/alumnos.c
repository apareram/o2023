/*
@file invertirFrase.c
@brief Se requiere de un programa para un usuario que permita administrar 
       los resultados de varios alumnos de las materias de Cálculo I, 
       Física I y Programación I. Se desean obtener los promedios y 
       seleccionar los alumnos que tengan un promedio determinado por el 
       usuario. 
       Un archivo de texto de nombre alumnos.txt contiene los datos de 
       alumnos en el siguiente formato:
            <nombre>\t<cal_cálculo>\t<cal_física>\t<cal_programación>\n

       Haga un programa que ayude al usuario a manipular los datos con la 
       siguiente funcionalidad: El programa se ejecutará con la siguiente 
       línea de comando:
            $./alumnos.exe <archivo_de_entrada> <promedio>
       a) A partir de la línea de comando, diseñe un módulo que lea los 
          datos del archivo de texto e inserte los datos de los alumnos en
          una lista LIFO. Verifique que los datos de los alumnos en la lista 
          LIFO están correctos recorriendo la lista y mandando imprimir los 
          datos completos de cada nodo de la lista en pantalla.
       b) Diseñe una función que permita obtener los promedios de los 
          alumnos con un filtro. En la línea de comando el usuario va a 
          ingresar un número real para hacer un filtro de los alumnos que 
          tienen un promedio mayor o igual a este. Haga una función que 
          recorra la lista y genere un reporte de los alumnos y el promedio 
          igual o mayor al ingresado por el usuario en pantalla para 
          comprobar los resultados. Los datos deben quedar guardados en 
          promedios.txt con el siguiente formato:
                <nombre>\t<promedio>\n
@author Alberto Parera Méndez
@date 25/09/2023
*/

#include "tipos.h"

nodo1 *leerDatos(char nomArch[]);

int main(int arc, char *argv[])
{
    nodo1* inicio;
    inicio = NULL;
    inicio = leerDatos(argv[1]);

    return 0;
}