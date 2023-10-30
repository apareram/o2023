#include "tiposTienda.h"

void leerTxt(char *nomArch, refs *fila, refs *nav);
void leerBin(char *nomArch, refs *fila, refs *nav);
void imprimirListaDobleCirc(refs fila);
void imprimirListaDoble(refs nav);



int main (int argc, char *argv[])
{
    refs cola, navegador;

    cola.inicio = NULL;
    cola.aux = NULL;
    cola.fin = NULL;

    navegador.inicio = NULL;
    navegador.fin = NULL;
    navegador.aux = NULL;

    if(argc != 3) 
    {
        printf("Uso: %s <nombre_archivo> -t|-b\n", argv[0]);
        exit(1);
    }
    if(strcmp(argv[2], "-t") == 0)
    {
        leerTxt(argv[1], &cola, &navegador);
    }
    else if(strcmp(argv[2], "-b") == 0)
    {
        leerBin(argv[1], &cola, &navegador);
    }
    else 
    {
        printf("Opción no reconocida: %s\n", argv[2]);
        exit(1);
    }
    printf("\nImpresión de la cola (categoría 1): ");
    imprimirListaDobleCirc(cola);
    printf("\nImpresión de la lista (categoría 2): ");
    imprimirListaDoble(navegador);

    return 0;
}