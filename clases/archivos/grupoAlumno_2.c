/*
@file grupoAlumno_2.c
@brief Este programa es un ejemplo para crear una lista de n alumnos con 
       siguientes datos: #cuenta, nombre, carrera, fecha de nacimiento
       y promedio.
       Modifique el programa para que tenga las siguientes funcionalidades:
       1) Desde la linea de comandos, indiquie el tamaño de alumnos a
          manipular.
          $./grupoAlumnos_2.exe 10
       2) Con el dato de tamaño genere un arreglo de alumno utilizando ADM.
       3) Haga una función que permita caprurar los n datos.
       4) Haga una función que reciba como argumento de I/O la dirección de
          un elemneto del arreglo y actualice los datos de ese alumno.
          La función se llamará actualizarDatos.
       5) Al final del programa, llame a dos funciones que guarden los datos
          de la lista de alumnos en: 1 archivo de texto "lista.txt" y otro
          de binario "lista.bin".
       6) Compruebe que los datos en el archivo binario están guardados
          correctamente.
       7) Modifique el programa para que si el usuario ingresa n <= 0 en
          la linea de comandos el programa lea la infromación del archivo
          de texto o binario y con la ayuda de ADM coloque correctamente
          los datos en memorio que esté referida o apuntada por el 
          apuntador grupo.
@autor Alberto Parera Méndez en la clase de Guillermo Gómez
@fecha 15/09/2023
*/
#include "defTipos.h"

void capturarAlumnos(int tam, tipoAlumno grupo[]);
void imprimirAlumnos(int tam, tipoAlumno grupo[]);
void actualizarDatos(tipoAlumno *alumno);
int guardarArchText(int tam, tipoAlumno grupo[]);
int guardarArchBin(int tam, tipoAlumno grupo[]);
int imprimirEnPantallaBin(char nomArch[]);
void cargarBinMem(tipoAlumno grupo[], int tam, char nomArch[]);
int contarAlumnosTxt(char nomArch[]);
void cargarTxtMEm(tipoAlumno grupo[], int tam, char nomArch[]);
int contarAlumnos(char nomArch[]);


int main (int argc, char *argv[])
{
    int tam, pos;
    tipoAlumno *grupo;
    char opcion;

    sscanf(argv[1], "%d", &tam);
    if(tam > 0)
    {
      grupo = (tipoAlumno *)malloc(tam * sizeof(tipoAlumno));

      if(grupo == NULL)
      {
         printf("\nNo hay memoria dsiponible.\n");
         exit(1);
      }

      capturarAlumnos(tam, grupo);
      imprimirAlumnos(tam, grupo);

      printf("\nDeseas modificar algun usuario ['s' | 'n']: \n");
      scanf(" %c", &opcion);
      if(opcion == 's')
      {
         printf("\nDame el número de alumno que desea actualizar: \n");
         scanf(" %d", &pos);
         actualizarDatos(&grupo[pos-1]);
         imprimirAlumnos(tam, grupo);
      }

      guardarArchText(tam, grupo);

      guardarArchBin(tam, grupo);

      imprimirEnPantallaBin("lista.bin");
    }
    else //lectura de los datos de los archivos
    {
      printf("\n¿Qué datos deseas cargar en memoria: archivo binario ['b'] o texto ['t']: \n");
      scanf(" %c", &opcion);
      if(opcion == 'b')
      {
         //tam = imprimirEnPantallaBin("lista.bin");
         imprimirEnPantallaBin("lista.bin");
         tam = contarAlumnos("lista.bin");
         printf("\nHay %d alumnos calculados en la función contar Alumnos\n", tam);
         grupo = (tipoAlumno *)malloc(tam * sizeof(tipoAlumno));
         if(grupo == NULL)
         {
            printf("\nNo hay memoria dsiponible.\n");
            exit(1);
         }

         cargarBinMem(grupo, tam, "lista.bin");
         imprimirAlumnos(tam, grupo);
      }
      else
      {
         if(opcion == 't')
         {
            tam = contarAlumnosTxt("lista.txt");
            grupo = (tipoAlumno *)malloc(tam * sizeof(tipoAlumno));
            if(grupo == NULL)
            {
               printf("\nNo hay memoria dsiponible.\n");
               exit(1);
            }
            cargarTxtMEm(grupo, tam, "lista.txt");
            imprimirAlumnos(tam, grupo);
         }
         else
         {
            printf("\nOpción no valida.\n");
         } 
      } 
    }

    return 0;
}