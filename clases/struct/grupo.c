/*
@file grupo.c
@brief Este programa es un ejemplo para crear una lista de n alumnos con 
       siguientes datos: #cuenta, nombre, carrera, fecha de nacimiento
       y promedio.
       1) sumarReales, que reciba el arreglo y entregue la suma.
@autor Alberto Parera Méndez en la clase de Guillermo Gómez
@fecha 05/09/2023
*/
#include <stdio.h>
#include <stdlib.h>

struct nacimiento
     {
        int dia;
        int mes;
        int ano;
     };

struct alumno 
     {
        int numCta;
        char nombre[80];
        char cadena[80];
        struct nacimiento fecha;
        float promedio;
     };

int main (void)
{
    struct alumno unAlumno;

    printf("\nDame el nombre: \n");
    scanf(" %[^\n]", unAlumno.nombre);
    printf("\nDame el promedio: \n");
    scanf(" %f", &unAlumno.promedio);
    printf("\nDame el mes: \n");
    scanf(" %d", &unAlumno.fecha.mes);

    return 0;
}