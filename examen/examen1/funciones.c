
/*
@file funciones.c
@brief Este  archivo contiene las funciones que son llamadas desde
       autos.c. 
@author Alberto Parera Méndez en el examenm de Guillermo Gómez
@date 29/09/2023
*/

#include "tipos.h"

/*
@brief Esta función agrega un nodo al inicio de la lista con la operación
       en autos.c.
@author Alberto Parera Méndez en el examenm de Guillermo Gómez
@date 29/09/2023
@param autos estructura de tipoAutos.
@param *pt es un apuntador del tipo nodo.
@return *pt es un apiuntador de tipo nodo que devuelve el nuevo inicio de
        la lista.
*/
extern nodo *push(tipoAutos coche, nodo *pt)
{
    nodo *nuevo;

    nuevo = (nodo *)malloc(sizeof(nodo));
    if(nuevo == NULL)
    {
        printf("\nNo hay memoria disponible.\n");
        exit(1);
    }
    nuevo->autos = coche;
    nuevo->next = pt;
    pt = nuevo;

    return pt;
}

/*
@brief Esta función copia lo que se encuentra en el acrhivo de texto y lo
       coloca en una lista LIFO.
@author Alberto Parera Méndez en el examenm de Guillermo Gómez
@date 29/09/2023
@param nomarch[] es una cadena de chars que contiene el nombre del archivo de
       texto.
@param *pt es un apuntador del tipo nodo.
@return *pt es un apiuntador de tipo nodo que devuelve el nuevo inicio de
        la lista.
*/
extern nodo *leerDatos(char nomArch[])
{
    FILE *fp;
    nodo *pt;
    tipoAutos coche;

    fp = fopen(nomArch, "r");
    if(fp == NULL)
    {
        printf("\nArchivo no disponible\n");
        exit(1);
    }

    pt = NULL;
    
    while(fscanf(fp, "%s\t%s\t%s\t%i\n", coche.marca, coche.modelo, coche.placa, &coche.ano) == 4)
    {
        pt = push(coche, pt);
    }
    fclose(fp);

    return pt;
}

/*
@brief Esta función imprime en pantalla lo que se encuentra en la lista 
       LIFO.
@author Alberto Parera Méndez en el examenm de Guillermo Gómez
@date 29/09/2023
@param *pt es un apuntador del tipo nodo.
*/
extern void imprimirLista(nodo *pt)
{
    printf("\nDatos en el archivo son:\n");
    if(pt != NULL)
    {
        while(pt != NULL)
        {
            printf("%s\t%s\t%s\t%i\n", pt->autos.marca, pt->autos.modelo, pt->autos.placa, pt->autos.ano);
            pt = pt->next;
        }
    }
    else
    {
        printf("\nLista vacía\n");
    }
    return;
}

/*
@brief Esta función guarda en un archivo de texto lo que se encuentra en
       una lista LIFO.
@author Alberto Parera Méndez en el examenm de Guillermo Gómez
@date 29/09/2023
@param *pt es un apuntador del tipo nodo.
*/
extern void guardarenTexto(nodo *pt)
{
    FILE *fp;
    
    fp = fopen("listaIvertida.txt", "w");
    if(pt != NULL)
    {
        while(pt != NULL)
        {
            fprintf(fp, "%s\t%s\t%s\t%i\n", pt->autos.marca, pt->autos.modelo, pt->autos.placa, pt->autos.ano);
            pt = pt->next;
        }
    }
    else
    {
        printf("\nLista vacía\n");
    }
    fclose(fp);

    return;
}

/*
@brief Esta función imprime en pantalla un peroprte de los autos que se 
       deben verificar. Para esto recorre la lista y hace una serie de
       comparaciones.
@author Alberto Parera Méndez en el examenm de Guillermo Gómez
@date 29/09/2023
@param *aux es un apuntador del tipo nodo.
*/
extern void reporteVerificacion(nodo *aux)
{
    nodo *temp = aux; 

    printf("\nReporte de meses en que se deben verificar los autos:\n");

    while(temp != NULL)
    {
        if((temp->autos.placa[5] == '5') || (temp->autos.placa[5] == '6')) 
        {
            printf("El %s %s con placa: %s se debe verificar entre Julio y Agosto.\n", temp->autos.marca, temp->autos.modelo, temp->autos.placa);
        }
        if((temp->autos.placa[5] == '7') || (temp->autos.placa[5] == '8')) 
        {
            printf("El %s %s con placa: %s se debe verificar entre Agosto y Septiembre.\n", temp->autos.marca, temp->autos.modelo, temp->autos.placa);
        }
        if((temp->autos.placa[5] == '3') || (temp->autos.placa[5] == '4')) 
        {
            printf("El %s %s con placa: %s se debe verificar entre Septiembre y Octubre.\n", temp->autos.marca, temp->autos.modelo, temp->autos.placa);
        }
        if((temp->autos.placa[5] == '1') || (temp->autos.placa[5] == '2')) 
        {
            printf("El %s %s con placa: %s se debe verificar entre Octubre y Noviembre.\n", temp->autos.marca, temp->autos.modelo, temp->autos.placa);
        }
        if((temp->autos.placa[5] == '9') || (temp->autos.placa[5] == '0')) 
        {
            printf("El %s %s con placa: %s se debe verificar entre Noviembre y Diciembre.\n", temp->autos.marca, temp->autos.modelo, temp->autos.placa);
        }
        temp = temp->next;
    }

    return;
}

/*
@brief Esta funcion recorre la lista LIFO e imprime la información de los 
       nodos hasta que el usuario indique.
@author Alberto Parera Méndez en el examenm de Guillermo Gómez
@date 29/09/2023
@param *aux2 es un apuntador del tipo nodo.
*/
extern void recorrerNodos(nodo *aux2)
{
    nodo *temp2 = aux2;
    char op;
    int i = 1;
    
    printf("\nQuieres recorrer nodo por nodo la lista de autos ('s' | 'n'):\n");
    scanf(" %c", &op);
    if (op == 's')
    {
        printf("\n\nInforme de autos en la lista LIFO:\n");
    }
    while((op != 'n') && (temp2 != NULL))
    {
        printf("%i El auto actual: %s %s %i\n", i, temp2->autos.marca, temp2->autos.modelo, temp2->autos.ano);
        temp2 = temp2->next;
        i++;
        printf("\nDame la opcion ('s' | 'n'):\n");
        scanf(" %c", &op);
    }
    printf("\n\nFin de la lista.\n");

    return;
}
