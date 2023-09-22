/*
@file convLinea.c
@brief Haga un ejemplo que lea de la linea de comandos estos datos:
        $./convLinea.exe <nombre> <peso> <estatura>
        A partir de los datos de la linea de comandos, hafa lo siguiente
        1) construa esta frase y haga que imprima en la pantalla
            "Conozco a <nombre>, el/ella mide <Estatura> y pesa <peso>"
@autor Alberto Parera Mendez
@fecha 22/08/2023
*/
#include <stdio.h>

int main(int argc, char *argv[])
{
    float altura, peso;
    char nombre[80], frasefinal[150];
    
    if (argc == 4)
    {
        sscanf(argv[1], " %[^\n]", nombre);
        sscanf(argv[2], " %f", peso);
        sscanf(argv[3], " %f", altura);
        sprintf(frasefinal, "\nConozco a %s, el/ella mide %f y pesa %f", nombre, altura, peso);
        printf("\n%s\n", frasefinal);
    }

    return 0;
}