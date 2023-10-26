#include "tipos.h"

/*
 * @brief Esta función recibe un puntero de referencia y un entero;
 * construye un árbol jerárquico ascendente (del nivel 0 al n)
 * @author/autor caso de Guillermo Gómez Abascal
 * @param *pt es un puntero de tipo nodo.
 * @param *num es un entero.
 * @return pt es un puntero de tipo nodo que apunta al raíz del árbol construido.
 */
extern nodo *insertarNodArbol(nodo *pt, int num)
{
    nodo *nuevo, *aux;

    aux = pt;
    int salir = 1;
    nuevo = (nodo *)malloc(sizeof(nodo));
    if(nuevo == NULL)
    {
        printf("\nNo hay memoria disponible.");
        exit(1);
    }
    nuevo->num = num;
    nuevo->izq = NULL;
    nuevo->der = NULL;

    if(aux == NULL)
    {
        pt = nuevo;
        return pt;  // Retorna el nuevo nodo cuando el árbol está vacío
    }
    while(aux != NULL && salir != 0) 
    {
        if(num == aux->num) 
        {
            printf("El número %i ya existe en el árbol y no será insertado nuevamente.\n", num);
            free(nuevo); // Libera la memoria del nodo que no vamos a insertar.
            return pt; // Salimos de la función ya que el número ya existe en el árbol.
        } 
        else if(num > aux->num) 
        {
            if(aux->der != NULL) 
            {
                aux = aux->der;
            } 
            else 
            {
                aux->der = nuevo;
                salir = 0;
            }
        } 
        else 
        {
            if(aux->izq != NULL) 
            {
                aux = aux->izq;
            } 
            else 
            {
                aux->izq = nuevo;
                salir = 0;
            }
        }
    }

    return pt;
}

void guardarOrdEnt(int entero)
{
    FILE *fp;

    fp = fopen("ordenados.txt", "a");
    if(fp == NULL)
    {
        printf("Archivo no disponible.");
        exit(1);
    }

    fprintf(fp, "%d\n", entero);

    fclose(fp);

   return;
}
/*
 * @brief Esta función recibe un puntero de referencia y recorre
 * el árbol de izquierda a derecha de forma recursiva.
 * Imprime en pantalla el recorrido.
 * @author/autor Guillermo Gómez Abascal
 * @param *aux es un puntero de tipo nodo.
 * @return aux es un puntero de tipo nodo que apunta al raíz del árbol construido.
 */
extern void recorrer(nodo *aux) // en orden ascendente
{
    if(aux != NULL)
    {
        recorrer(aux->izq);
        printf("%i\n", aux->num);
        guardarOrdEnt(aux->num);
        recorrer(aux->der);
    }

    return;
}

extern void imprimirEnTxt(nodo *aux, FILE *fp2)
{
    if(aux != NULL)
    {
        imprimirEnTxt(aux->izq, fp2);  
        fprintf(fp2, "%i\n", aux->num);
        imprimirEnTxt(aux->der, fp2);  
    }
    return;
}
