/*
@file actualizarDatos.c
@brief Este programa permite manipular el archivo binario lista.bin 
       utilizando otras funciones; permite actualizr los datos.
       y promedio.
       Modifique el programa para que tenga las siguientes funcionalidades:
       1) En el programa principal, mueste en pantalla cuántos alumnos
          contiene el archivo lista.bin. Imprima en pantalla el resultado
          de la función.
       2) Pedir al usuario el número de alumnos que deseas modificar; con 
          ese dato, llamar a una función que reescriba los datos completos
          de un alumno en el archivo lista.bin en la posición que indico
          el usuario.
@autor Alberto Parera Méndez en la clase de Guillermo Gómez
@fecha 06/10/2023
*/

#include "defTipos.h"

int retotnatValor(char nomArch[]);
int imprimirEnPantallaBin(char nomArch[]);
void actualizarAlumno(int pos, char nomArch[]);


int main(void)
{
    int pos, numAlumnos;

    numAlumnos = retotnatValor("lista.bin");
    printf("\nEn el archivo lista.bin hay %d alumnos.\n", retotnatValor("lista.bin"));
    imprimirEnPantallaBin("lista.bin");
    printf("\nDame la posición del alumno que deseas modificar: ");
    scanf(" %d", &pos);
    if(pos > numAlumnos)
    {
        printf("\nCálculo fuera de rango del número de alumnos.\n");
    }
    else
    {
        actualizarAlumno(pos, "lista.bin");
        imprimirEnPantallaBin("lista.bin");
    }
    
    return 0;
}