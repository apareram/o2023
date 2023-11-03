#include "defTipos.h"

/*
 * @brief Esta función coloca los enteros que se encuentren en un archivo de texto en arreglo de enteros.
 * @author Alberto Parera Méndez 
 * @param nomArch es un apuntador al nombre del archivo recibido en la línea de comandos.
 * @param arr[] es un arreglo de enteros.
 * @return tam es un entero conteniendo el total de enteros en el archivo de texto.
 */
extern void colocarEnteros(char nomArch[], int arr[])
{
    int i = 0, numero;
    FILE *fp;

    fp = fopen(nomArch, "r");
    if(fp == NULL)
    {
        printf("\nArchivo no disponible\n");
        exit(1);
    }

    while(fscanf(fp, "%d", &numero) == 1)
    {
        arr[i] = numero;
        i++;
    }
    fclose(fp);

    return;
}

/*
 * @brief Esta función calcula el tamaño del cual va a ser el arreglo, para esto cuenta los enteros en 
          el archivo de texto.
 * @author Alberto Parera Méndez 
 * @param nomArch es un apuntador al nombre del archivo recibido en la línea de comandos.
 * @return tam es un entero conteniendo el total de enteros en el archivo de texto.
 */
extern int calcularTam(char nomArch[])
{
    FILE *fp;
    int tam = 0, numero = 0;

    fp = fopen(nomArch, "r");
    if(fp == NULL)
    {
        printf("\nArchivo no disponible\n");
        exit(1);
    }
    while(fscanf(fp, "%d", &numero) == 1)
    {
        tam++;
    }
    fclose(fp);

    return tam;
}

/*
 * @brief Esta función recibe un arreglo con números deordenados y el tamaño de dicho arreglo, e imprime
          el contenido del arreglo.
 * @author Alberto Parera Méndez 
 * @param arr[] es un arreglo de enteros.
 * @param size es un entero que indíca el tamaño del arreglo.
 * @return pt es un puntero de tipo nodo que apunta al raíz del árbol construido.
 */
extern void imprimirArreglo(int arr[], int size)
{
    int i;
    printf("\nLos enteros en el arreglo están ahora así: \n");
    for(i = 0; i < size; i++)
    {
        printf("\n %d\n", arr[i]);
    }

    return;
}

/*
 * @brief Esta función recibe un puntero de referencia y un entero; construye un árbol jerárquico 
          ascendente (del nivel 0 al n).
 * @author Alberto Parera Méndez 
 * @param *pt es un puntero de tipo nodo.
 * @param *num es un entero.
 * @return pt es un puntero de tipo nodo que apunta al raíz del árbol construido.
 */
nodo *insertarNodArbol(nodo *pt, int num)
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
    nuevo->dato = num;
    nuevo->izq = NULL;
    nuevo->der = NULL;

    if(aux == NULL)
    {
        pt = nuevo;
        return pt;  // Retorna el nuevo nodo cuando el árbol está vacío
    }
    while(aux != NULL && salir != 0) 
    {
        if(num == aux->dato) 
        {
            printf("El número %i ya existe en el árbol y no será insertado nuevamente.\n", num);
            free(nuevo); // Libera la memoria del nodo que no vamos a insertar.
            return pt; // Salimos de la función ya que el número ya existe en el árbol.
        } 
        else if(num > aux->dato) 
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

/*
 * @brief Esta función recibe un entero y lo guarda en un archivo de texto
 * @author/autor Alberto Parera Méndez
 * @param entero es un número entero
 */
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
 * @brief Esta función recibe un puntero de referencia y recorre el árbol de izquierda a derecha de 
          forma recursiva.
 * Imprime en pantalla el recorrido.
 * @author Alberto Parera Méndez
 * @param *aux es un puntero de tipo nodo.
 * @return aux es un puntero de tipo nodo que apunta al raíz del árbol construido.
 */
extern void recorrer(nodo *aux) // en orden ascendente
{
    if(aux != NULL)
    {
        recorrer(aux->izq);
        printf("%i\n", aux->dato);
        guardarOrdEnt(aux->dato);
        recorrer(aux->der);
    }

    return;
}

void imprimirEnTxt(nodo *aux, FILE *fp2)
{
    if(aux != NULL)
    {
        imprimirEnTxt(aux->izq, fp2);  
        fprintf(fp2, "%i\n", aux->dato);
        imprimirEnTxt(aux->der, fp2);  
    }
    return;
}

/*
 * @brief Esta función recibe un entero ingresado por el usuario y busca si se encuentra en el árbol
 * @author Alberto Parera Méndez
 * @param *aux es un puntero de tipo nodo.
 * @param busca es un entero ingresado po el usuario
 * @return aux es un puntero de tipo nodo que apunta al entero ingresado por el usuario.
 */
extern nodo *buscarDirecto(int busca, nodo *aux)
{
    int comparaciones = 1;
    while((aux != NULL) && (busca != aux->dato))
    {
        if(busca < aux->dato)
        {
            aux = aux->izq;
        }
        else
        {
            aux = aux->der;
        }
        comparaciones++;
    }

    printf("\nSe realizaron %d comparaciones.\n", comparaciones);
    printf("\nSe llegó al nivel %d.\n", (comparaciones - 1));

    return aux;
}

/*
 * @brief Esta función lee lo que se encuentra en un archivo de texto e ingresa los datos en un árbol
          utilizando la función insertarNodArbol
 * @author Alberto Parera Méndez
 * @param nomArch es un puntero de un archivo de texto.
 * @param raiz es un doble puntero que apunta a la direccion de la direccion del nodo raíz del árbol.
 */
extern void crearArbol(char nomArch[], nodo **raiz)
{
    int numero, resultado;
    FILE *fp;

    fp = fopen(nomArch, "r");
    if(fp == NULL)
    {
        printf("Archivo no disponible.");
        exit(1);
    }
    while(fscanf(fp, "%i", &numero) == 1)
    {
        *raiz = insertarNodArbol(*raiz, numero);
    }

    fclose(fp);

    return;
}