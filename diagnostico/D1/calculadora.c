/*
@file calculadora.c
@brief Haga una calculadora desde la línea de comandos. El usuario debe indicar 
       la operación desde la línea de comandos como se muestra en el ejemplo:
       $./calculadora.exe 6.5 x 8.6
       Tu resultado es: 55.90
       Las operaciones que se pueden realizar son multiplicación (‘x’), división (‘/’), 
       resta (‘-‘) y suma (‘+’). Valide que los argumentos ingresados por el usuario 
       están correctos.
@autor Alberto Parera Méndez
@fecha 25/08/2023
*/

#include <stdio.h>

int main (int argc, char *argv[])
{
    float num1, num2, resu;
    char sim[10], frase[40];
    
    if (argc == 4)
    {
        sscanf(argv[1], " %f", &num1);
        sscanf(argv[2], " %s", &sim[0]);
        sscanf(argv[3], " %f", &num2);

        if(sim[0] == 'x')
        {
            resu = num1*num2;
            sprintf(frase, "\nTu resultado es: %f", resu);
            printf("\n%s\n", frase);
        }

        if(sim[0] == '/')
        {
            resu = num1/num2;
            sprintf(frase, "\nTu resultado es: %f", resu);
            printf("\n%s\n", frase); 
        }

        if(sim[0] == '+')
        {
            resu = num1+num2;
            sprintf(frase, "\nTu resultado es: %f", resu);
            printf("\n%s\n", frase);
        }

        if(sim[0] == '-')
        {
            resu = num1-num2;
            sprintf(frase, "\nTu resultado es: %f", resu);
            printf("\n%s\n", frase);
        }   
    }
    
    return 0;
}