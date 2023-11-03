#include "defTipos.h"

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