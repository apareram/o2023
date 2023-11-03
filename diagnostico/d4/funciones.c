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

/*
* @brief Función de ordenamiento en la que compara los datos en el arreglo e intercambia los que no tienen el orden pedido por el usuario.                                         
* @author Ely Ibarra, Bárbara Mendoza, Denissa Romo.
* @param arreglo de tipo entero.
* @param variable elemento de tipo entero
* @return lista ordenada
*
*/
extern void bubbleSort(int arr[], int elem)
{
  int i, j, temp;

  for(i=0; i<= (elem-2);i++)
    {
      for(j= (i+1); j<=(elem-1);j++)
        {
          if(arr[i] > arr[j])
            {

              temp = arr[i];

              arr[i]=arr[j];

              arr[j]=temp;
            }
        }
    }
  return;
}

/*
* @brief función que imprime el arreglo de datos en un archivo txt de forma ordenada
* @author Ely Ibarra, Bárbara Mendoza, Denissa Romo.
* @param arreglo de tipo int
* @param variable nomArch del tipo char
* @return
*
*/
extern void agregarArch(int arr[], int size)
{
  FILE *fp;
  int i;

  fp = fopen("ordenadoBubble.txt", "w");
  if(fp == NULL)                                                                   {                   
    printf("\nArchivo no disponible.\n");
    exit(1);
  }
  else
    {
     for(i=0; i<size;i++)                                                              {
       fprintf(fp, "%i\n", arr[i]);
       }
    }

  return;
}

void quickSort(int arr[], int n)
{
    int i = 0, j = n - 1, temp, x = arr[j / 2];

    do {
        while (arr[i] < x)
        {
            i++;
        }
        while (arr[j] > x)
        {
            j--;
        }
        if (i < j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        else
        {
          if (i > j) {
            break;
          }
        }
    } while (i++ <= j--);

    if (j > 0) {
        quickSort(arr, j + 1);
    }
    if (i < n) {
        quickSort(arr + i, n - i);
    }
}

extern int busquedaLineal(int x, int arr[], int n)
{
    int i = 0;
    while((i < n) && (x > arr[i]))
    { 
        i++;
        if(i == (n - 1))
        { 
            break;
        }
    }
    printf ("\nLa posición final es: %i\n", i);

    if(x != arr[i])
    {
        i = -1;
    }// cuando termine el while, i tiene el valor de n-1, última posición
    return i;
}
extern int busquedaBinariaLineal (int x, int arr[], int n)
{
    int medio, izq, der;
    izq = 0;
    der = n-1;
    if (arr[izq] == x)
    {
        der = izq;
    }
    else
    {
        while((der - izq) > 1 )
        {
            medio = (izq + der) /2;
            if(x <= arr [medio])
            { 
                der = medio;
            }
            else
            {
                izq = medio;
            }
        }
    }
    if(x != arr[der])
    {
        der = -1;
    }

    return der;
}

/*
* @brief en esta función se insertan los datos de enteros.txt en una lista doble simple
*
* @param nav que es de tipo refs
* @param dat que es de tipo entero (declarado en el struct)
* @return void
*/
extern void insertarListaDoble(referencias *nav, int dat)
{
  nodo *nuevo;
  nuevo = (nodo *)malloc(sizeof(nodo));
  if(nuevo == NULL)
    {
      printf("\nNo hay memoria disponible.\n");
      exit (1);
    }

  nuevo->izq = NULL;
  nuevo->der = NULL;
  nuevo->dato = dat;
 
  if ((nav->inicio == NULL) && (nav->fin == NULL))
    {
      nav->inicio = nuevo;
      nav->fin = nuevo;
      nav->actual = nuevo;
    }
  else
    {
      nuevo->izq = nav->fin;
      nav->fin->der =nuevo;
      nav->fin = nuevo;
    }

 
  return;
}

/*
* @brief en esta función se acomodan los datos en un lista doble lineal
*
* @param filaO que es de tipo refs
* @param dat que es de tipo entero (declarado en el struct)
* @return void
*/
extern void insertarListaOrdenada(int dat, referencias *filaO)
{
    nodo *nuevo;

    nuevo = (nodo *)malloc(sizeof(nodo));
    if(nuevo == NULL)
    {
        printf("\nNo hay memoria disponible.\n");
        exit(1);
    }
    nuevo->dato = dat;

    if((filaO->inicio == NULL) && (filaO->fin == NULL))
    {
        filaO->inicio = nuevo;
        filaO->fin = nuevo;
    }
    else
    {
        if(nuevo->dato < filaO->inicio->dato)
        {
            nuevo->der = filaO->inicio;
            filaO->inicio->izq = nuevo;
            filaO->inicio = nuevo;
        }
        else
        {
            if(nuevo->dato > filaO->fin->dato)
            {
                nuevo->izq = filaO->fin;
                filaO->fin->der = nuevo;
                filaO->fin = nuevo;
            }
            else
            {
                filaO->actual = filaO->inicio->der;
                while(nuevo->dato > filaO->actual->dato)
                {
                    filaO->actual = filaO->actual->der;
                }
                nuevo->der = filaO->actual;
                nuevo->izq = filaO->actual->izq;
                filaO->actual->izq->der = nuevo;
                filaO->actual->izq = nuevo;
            }
        }
    }

    return;
}

/*
* @brief en esta función se imprimen los datos de la lista ordenada
*
* @param fila que es de tipo refs
* @return void
*/
extern void imprimirListaDoble (referencias fila)
{
  fila.actual = fila.inicio;
  if((fila.inicio == NULL) && (fila.fin == NULL))
    {
      printf("\nNo puedo imprimir una lista vacía.\n");
    }
  else
    {
      do
        {
            printf("\n%d", fila.actual->dato);
            fila.actual = fila.actual->der;
        }while(fila.actual != fila.fin->der);
    }

  return;
}

/*
* @brief en esta función se busca en la lista ordenada un número introducido por el usuario y se devuelve la dirección de memoria en la que se encuentra
*
* @param filaO que es de tipo refs
* @param numero que es un entero
* @return dirección de memoria de filaO
*/
extern nodo *buscarNumero(referencias filaO, int numero)
{
    filaO.actual = filaO.inicio;

    if(filaO.actual == NULL)
    {
        printf("\nLista vacía.\n"); 
    }
    else
    {
        while(filaO.actual != NULL)
        {
            if(numero == filaO.actual->dato)
            {
                return filaO.actual;
            }
            else
            {
                filaO.actual = filaO.actual->der;
            }
        }
    }

  return filaO.actual;
}

/*
* @brief en esta función se guarda la lista ordenada en un archivo de texto.
*
* @param filaO que es de tipo refs
* @return void
*/
extern void guardarArchText (referencias filaO)
{
  FILE *fp;

  filaO.actual = filaO.inicio;
 
  fp = fopen("enterosOrd.txt", "w");
  if (fp == NULL)
    {
      printf ("\nArchivo no disponible.\n");
      exit(1);
    }
  while(filaO.actual != NULL)
    {
      fprintf(fp, "%d\t", filaO.actual->dato);
      filaO.actual = filaO.actual->der;
    }
  fclose(fp);

  return;
}