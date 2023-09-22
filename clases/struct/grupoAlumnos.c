/*
@file grupo.c
@brief Este programa es un ejemplo para crear una lista de n alumnos con 
       siguientes datos: #cuenta, nombre, carrera, fecha de nacimiento
       y promedio.
       Modifique el programa para que tenga las siguientes funcionalidades:
       1) Desde la linea de comandos, indiquie el tamaño de alumnos a
          manipular.
          $./grupoAlumnos.exe 10
       2) Con el dato de tamaño genere un arreglo de alumno utilizando ADM.
       3) Haga una función que permita caprurar los n datos.
       4) Haga una función que reciba como argumento de I/O la dirección de
          un elemneto del arreglo y actualice los datos de ese alumno.
          La función se llamará actualizarDatos.
@autor Alberto Parera Méndez en la clase de Guillermo Gómez
@fecha 05/09/2023
*/
#include "defTipos.h"

void capturarAlumnos(int tam, tipoAlumno grupo[]);
void imprimirAlumnos(int tam, tipoAlumno grupo[]);
void actualizarDatos(tipoAlumno *alumno);

int main (int argc, char *argv[])
{
    int tam, pos;
    tipoAlumno *grupo;

    sscanf(argv[1], "%d", &tam);
    grupo = (tipoAlumno *)malloc(tam * sizeof(tipoAlumno));

    if(grupo == NULL)
    {
        printf("\nNo hay memoria dsiponible.\n");
        exit(1);
    }

    capturarAlumnos(tam, grupo);
    imprimirAlumnos(tam, grupo);

    printf("\nDame el número de alumno que desea actualizar: \n");
    scanf(" %d", &pos);
    actualizarDatos(&grupo[pos-1]);

    imprimirAlumnos(tam, grupo);

    return 0;
}