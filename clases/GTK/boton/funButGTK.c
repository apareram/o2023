#include <string.h>

void mezclarTextos(char final[], char inicial[], int clicks)
{
    strcpy(texto, "Se han realizado estos clicks: ");
    clicks ++;
    mezclarTextos(texto2, texto, clicks);
    sprintf(texto2, "%s%d", texto, clicks);

    return;
}