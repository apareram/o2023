#include "tiposTienda.h"

void insertarCola(cat1 dat1, refs *fila)
{
    nodo *nuevo;
    
    nuevo = (nodo *)malloc(sizeof(nodo));
    if(nuevo == NULL)
    {
        printf("\nNo hay memoria disponible\n");
        exit(1);
    }
    
    nuevo->datos1 = dat1;

    if((fila->inicio == NULL) && (fila->fin == NULL))
    {
        nuevo->der = nuevo;
        nuevo->izq = nuevo;
        fila->inicio = nuevo;
        fila->fin = nuevo;
    }
    else
    {
        nuevo->izq = fila->fin;
        nuevo->der = fila->inicio;
        fila->fin->der = nuevo;
        fila->inicio->izq = nuevo;
        fila->fin = nuevo;
    }

    return;
}

void insertarListaDoble(refs *nav, cat2 dat2)
{
    nodo *nuevo;

    nuevo = (nodo *)malloc(sizeof(nodo));
    if(nuevo == NULL)
    {
        printf("\nNo hay memoria disponible.\n");
        exit(1);
    }

    nuevo->izq = NULL;
    nuevo->der = NULL;
    nuevo->datos2 = dat2;

    if((nav->inicio == NULL) && (nav->fin == NULL))
    {
        nav->inicio = nuevo;
        nav->fin = nuevo;
    }
    else
    {
        nuevo->izq = nav->fin;
        nav->fin->der = nuevo;
        nav->fin = nuevo;
    }

    return;
}

extern void leerTxt(char *nomArch, refs *fila, refs *nav)
{
    FILE *fp;
    cat1 datos1;
    cat2 datos2;

    fp = fopen(nomArch, "r");
    if(fp == NULL)
    {
        printf("\nArchivo no disponible.\n");
        exit(1);
    }
    while(fscanf(fp, "%d\t %[^\t] %[^\t]%f\t%d\n", &datos1.clave, datos1.categoria, datos1.producto, &datos1.precio, &datos1.inventario) == 5)
    {
        if((strcmp("Electrónica", datos1.categoria) == 0) || (strcmp("Bebés", datos1.categoria) == 0) || (strcmp("Libros", datos1.categoria) == 0))
        {
            insertarCola(datos1, fila);
        }
        else if((strcmp("Ropa", datos1.categoria) == 0) || (strcmp("Hogar", datos1.categoria) == 0) || (strcmp("Música", datos1.categoria) == 0))
        {
            datos2.clave = datos1.clave;
            strcpy(datos2.categoria, datos1.categoria);
            strcpy(datos2.producto, datos1.producto);
            datos2.precio = datos1.precio;
            datos2.inventario = datos1.inventario;
            insertarListaDoble(nav, datos2);
        }
    }
    fclose(fp);

    return;
}

extern void leerBin(char *nomArch, refs *fila, refs *nav)
{
    FILE *fp;
    cat1 datos1;
    cat2 datos2;

    fp = fopen(nomArch, "rb");
    if(fp == NULL)
    {
        printf("\nArchivo no disponible.\n");
        exit(1);
    }
    while(fread(&datos1, sizeof(cat1), 1, fp) == 1)
    {
        if((strcmp("Electrónica", datos1.categoria) == 0) || (strcmp("Bebés", datos1.categoria) == 0) || (strcmp("Libros", datos1.categoria) == 0))
        {
            insertarCola(datos1, fila);
        }
        else if((strcmp("Ropa", datos1.categoria) == 0) || (strcmp("Hogar", datos1.categoria) == 0) || (strcmp("Música", datos1.categoria) == 0))
        {
            datos2.clave = datos1.clave;
            strcpy(datos2.categoria, datos1.categoria);
            strcpy(datos2.producto, datos1.producto);
            datos2.precio = datos1.precio;
            datos2.inventario = datos1.inventario;
            insertarListaDoble(nav, datos2);
        }
    }
    fclose(fp);

    return;
}

extern void imprimirListaDobleCirc(refs fila)
{
    fila.aux = fila.inicio;

    if((fila.inicio == NULL) && (fila.fin == NULL))
    {
        printf("\nNo puedo imprimir una lista vacía.\n");
    }
    else
    {
        do
       {
            printf("\nClaeve: %d", fila.aux->datos1.clave);
            printf("\tCategoría: %s", fila.aux->datos1.categoria);
            printf("\tProducto: %s", fila.aux->datos1.producto);
            printf("\tPrecio: %f\n\n", fila.aux->datos1.precio);
            printf("\tInventario: %d\n\n", fila.aux->datos1.inventario);
            fila.aux = fila.aux->der;
       }while(fila.aux != fila.inicio); 
    }

    return;
}

extern void imprimirListaDoble(refs nav)
{
    nav.aux = nav.inicio;

    if((nav.inicio == NULL) && (nav.fin == NULL))
    {
        printf("\nLista vacía.\n");
    }
    while(nav.aux != NULL)
    {
        printf("\nClaeve: %d", nav.aux->datos2.clave);
        printf("\tCategoría: %s", nav.aux->datos2.categoria);
        printf("\tProducto: %s", nav.aux->datos2.producto);
        printf("\tPrecio: %f\n\n", nav.aux->datos2.precio);
        printf("\tInventario: %d\n\n", nav.aux->datos2.inventario);
        nav.aux = nav.aux->der;
    }

    return;
}