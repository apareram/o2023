/*
@file convCadena.c
@brief este ejemplo es para entender sscanf y sprintf
@autor Alberto Parera Méndez
@fecha 22/08/2023
*/
#include <stdio.h>

int main (int argc, char *argv[])
{
    float altura, peso;
    char frase[80], cad1[20], cad2[20];

    printf("\nEscribe una frase que tenga la altura y peso de alguien: ");
    sscanf(" %[^\n]", frase);
    sscanf(frase, "%s %f %s %f", cad1, &altura, cad2, &peso);
    printf("Esta persona %s estos %f kilogramos y %s estos %f metros.\n", cad2, peso, cad1, altura);

    return 0;
}