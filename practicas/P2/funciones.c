#include "tiposTienda.h"

extern void insertarCola(cat1 dat1, refs *refscirc)
{
    nodo *nuevo;
    
    nuevo = (nodo *)malloc(sizeof(nodo));
    if(nuevo == NULL)
    {
        printf("\nNo hay memoria disponible\n");
        exit(1);
    }
    nuevo->datos1 = dat1;
    if((refscirc->inicio == NULL) && (refscirc->fin == NULL))
    {
        nuevo->der = nuevo;
        nuevo->izq = nuevo;
        refscirc->inicio = nuevo;
        refscirc->fin = nuevo;
    }
    else{
        nuevo->izq = refscirc->fin;
        nuevo->der = refscirc->inicio;
        refscirc->fin->der = nuevo;
        refscirc->inicio->izq = nuevo;
        refscirc->fin = nuevo;
    }

    return;
}

extern void insertarListaDoble(refs *refslin, cat2 dat2)
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

    if((refslin->inicio == NULL) && (refslin->fin == NULL))
    {
        refslin->inicio = nuevo;
        refslin->fin = nuevo;
    }
    else
    {
        nuevo->izq = refslin->fin;
        refslin->fin->der = nuevo;
        refslin->fin = nuevo;
    }

    return;
}

extern void leerTxt(char *nomArch, nav *nav)
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
    while(fscanf(fp, " %d\t %[^\t] %[^\t] %f\t %d\n", &datos1.clave, datos1.categoria, datos1.producto, &datos1.precio, &datos1.inventario) == 5)
    {
        if((strcmp("Electrónica", datos1.categoria) == 0) || (strcmp("Bebés", datos1.categoria) == 0) || (strcmp("Libros", datos1.categoria) == 0))
        {
            insertarCola(datos1, nav->refscirc);
        }
        else if((strcmp("Ropa", datos1.categoria) == 0) || (strcmp("Hogar", datos1.categoria) == 0) || (strcmp("Música", datos1.categoria) == 0))
        {
            datos2.clave = datos1.clave;
            strcpy(datos2.categoria, datos1.categoria);
            strcpy(datos2.producto, datos1.producto);
            datos2.precio = datos1.precio;
            datos2.inventario = datos1.inventario;
            insertarListaDoble(nav->refslin, datos2);
        }
    }
    fclose(fp);

    return;
}

extern void leerBin(char *nomArch, nav *nav)
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
            insertarCola(datos1, nav->refscirc);
        }
        else if((strcmp("Ropa", datos1.categoria) == 0) || (strcmp("Hogar", datos1.categoria) == 0) || (strcmp("Música", datos1.categoria) == 0))
        {
            datos2.clave = datos1.clave;
            strcpy(datos2.categoria, datos1.categoria);
            strcpy(datos2.producto, datos1.producto);
            datos2.precio = datos1.precio;
            datos2.inventario = datos1.inventario;
            insertarListaDoble(nav->refslin, datos2);
        }
    }
    fclose(fp);

    return;
}

extern void imprimirListaDobleCirc(refs refscirc)
{
    refscirc.aux = refscirc.inicio;

    if((refscirc.inicio == NULL) && (refscirc.fin == NULL))
    {
        printf("\nNo puedo imprimir una lista vacía.\n");
    }
    else
    {
        do
       {
            printf("Clave: %d\n", refscirc.aux->datos1.clave);
            printf("Categoría: %s\n", refscirc.aux->datos1.categoria);
            printf("Producto: %s\n", refscirc.aux->datos1.producto);
            printf("Precio: %f\n", refscirc.aux->datos1.precio);
            printf("Inventario: %d\n\n", refscirc.aux->datos1.inventario);
            refscirc.aux = refscirc.aux->der;
       }while(refscirc.aux != refscirc.inicio); 
    }

    return;
}

extern void imprimirListaDoble(refs refslin)
{
    refslin.aux = refslin.inicio;

    if((refslin.inicio == NULL) && (refslin.fin == NULL))
    {
        printf("\nLista vacía.\n");
    }
    while(refslin.aux != NULL)
    {
        printf("Clave: %d\n", refslin.aux->datos2.clave);
        printf("Categoría: %s\n", refslin.aux->datos2.categoria);
        printf("Producto: %s\n", refslin.aux->datos2.producto);
        printf("Precio: %f\n", refslin.aux->datos2.precio);
        printf("Inventario: %d\n\n", refslin.aux->datos2.inventario);
        refslin.aux = refslin.aux->der;
    }

    return;
}

extern nodocar *enqueue(nav *nav, datcar data)
{
    nodocar *nuevo;

    nuevo = (nodocar *)malloc(sizeof(nodocar));
    if(nuevo == NULL)
    {
        printf("\nNo hay memoria disponible.\n");
        exit(1);
    }
    nuevo->datos = data;
    nuevo->next = NULL;
    if((nav->iniciocar == NULL) && (nav->fincar == NULL))
    {
        nav->iniciocar = nuevo;
        nav->fincar = nuevo;
    }
    else
    {
        nav->fincar->next = nuevo;
        nav->fincar = nuevo;
    }
    return nav->iniciocar;
}

extern void deQueue(nodocar **iniciocar, nodocar **fincar)
{
    nodocar *borra;
    if(*iniciocar == NULL) // Si la cola está vacía, no hay nada que desencolar
    {
        printf("\nLa cola está vacía.\n");
        return; // Salir de la función si la cola está vacía
    }

    borra = *iniciocar; // Guardar el nodo actual a borrar

    if(*iniciocar == *fincar) // Si hay un solo nodo en la cola
    {
        *iniciocar = NULL;
        *fincar = NULL;
    }
    else // Si hay más de un nodo
    {
        *iniciocar = (*iniciocar)->next; // Mover el inicio al siguiente nodo
    }

    free(borra); // Liberar la memoria del nodo borrado

    return;
}

extern void agregarCarrito1(nav *nav)
{
    int compra;
    datcar articulo;

    system("clear");


    printf("\nEl producto es: %s\n", nav->refscirc->aux->datos1.producto);
    printf("El inventario disponible es: %i\n", nav->refscirc->aux->datos1.inventario);
    printf("\n¿Cuántos artículos desea agregar?\n");
    scanf(" %i", &compra);
    if(compra > nav->refscirc->aux->datos1.inventario)
    {
        printf("\n No tenemos tantos en la tienda, vuelva a intentar con una menor cantidad\n");
    }
    else
    {
        nav->refscirc->aux->datos1.inventario = nav->refscirc->aux->datos1.inventario - compra;
        strcpy(articulo.categoria, nav->refscirc->aux->datos1.categoria);
        strcpy(articulo.producto, nav->refscirc->aux->datos1.producto);
        articulo.precio = nav->refscirc->aux->datos1.precio;
        articulo.cantidad = compra;
        nav->iniciocar = enqueue(nav, articulo);
    }

    return;
}

extern void agregarCarrito2(nav *nav)
{
    int compra;
    datcar articulo;

    system("clear");


    printf("\nEl producto es: %s\n", nav->refslin->aux->datos2.producto);
    printf("El inventario disponible es: %i\n", nav->refslin->aux->datos2.inventario);
    printf("\n¿Cuántos artículos desea agregar?\n");
    scanf(" %i", &compra);
    if(compra > nav->refslin->aux->datos2.inventario)
    {
        printf("\n No tenemos tantos en la tienda, vuelva a intentar con una menor cantidad\n");
    }
    else
    {
        nav->refslin->aux->datos2.inventario = nav->refslin->aux->datos2.inventario - compra;
        strcpy(articulo.categoria, nav->refslin->aux->datos2.categoria);
        strcpy(articulo.producto, nav->refslin->aux->datos2.producto);
        articulo.precio = nav->refslin->aux->datos2.precio;
        articulo.cantidad = compra;
        nav->iniciocar = enqueue(nav, articulo);
    }

    return;
}

extern void mostrarCarrito(nodocar *pt)
{
    float precTot = 0.0;
    int artTot = 0; 

    printf("\nArtículos guardados en el carrito:\n");
    if(pt != NULL)
    {
        while(pt != NULL)
        {
            printf("%s (%d)\n", pt->datos.producto, pt->datos.cantidad);
            precTot += (pt->datos.precio * pt->datos.cantidad);
            artTot += pt->datos.cantidad;
            pt = pt->next;
        }
        printf("\nSubtotal (%d productos): $%f\n", artTot, precTot);
    }
    else
    {
        printf("\nLista vacía\n");
    }
    return;
}

extern void navegarCategoria1(nav *nav) 
{
    char opc;
    int flag;

    nav->refscirc->aux = nav->refscirc->inicio;

    if ((nav->refscirc->inicio == NULL) && (nav->refscirc->fin == NULL)) {
        printf("\nNo puedo imprimir una lista vacía.\n");
    } else {
        do {

            printf("----- Categoría 1 - Productos -----\n");
            printf("Clave: %d\n", nav->refscirc->aux->datos1.clave);
            printf("Categoría: %s\n", nav->refscirc->aux->datos1.categoria);
            printf("Producto: %s\n", nav->refscirc->aux->datos1.producto);
            printf("Precio: %.2f\n", nav->refscirc->aux->datos1.precio);
            printf("Inventario: %d\n\n", nav->refscirc->aux->datos1.inventario);

            printf("Opciones:\n");
            printf("a) Anterior   b) Regresar al menú   c) Agregar al carrito   d) Siguiente   e) Salir del programa\n");
            printf("Seleccione una opción: ");
            scanf(" %c", &opc);

            switch (opc) {
                case 'a':
                case 'A':
                    flag = 0;
                    nav->refscirc->aux = nav->refscirc->aux->izq;
                    system("clear");
                    break;
                case 'd':
                case 'D':
                    flag = 0;
                    nav->refscirc->aux = nav->refscirc->aux->der;
                    system("clear");
                    break;
                case 'b':
                case 'B':
                    flag = 1;
                    system("clear");
                    break;
                case 'c':
                case 'C':
                    flag = 0;
                    if (nav->refscirc->aux->datos1.inventario == 0) {
                        printf("El producto no está disponible por el momento.\n");
                    } else {
                        system("clear");
                        agregarCarrito1(nav);
                    }
                    break;
                case 'e':
                case 'E':
                    printf("¿Desea salir completamente del programa?, se borrarán los productos guardados en el carrito. (s/n) \n");
                    scanf(" %c", &opc);
                    if (opc == 's' || opc == 'S') {
                        exit(1);
                    }
                    break;
                default:
                    printf("Opción no válida. Por favor, seleccione una opción del menú.\n");
            }
        } while (flag == 0);
    }

    return;
}

extern void navegarCategoria2(nav *nav) 
{
    char opc;
    int flag = 0;

    nav->refslin->aux = nav->refslin->inicio;

    if ((nav->refslin->inicio == NULL) && (nav->refslin->fin == NULL)) {
        printf("\nLista vacía.\n");
    }

    while (flag != 1) {

        printf("----- Categoría 2 - Productos -----\n");
        printf("Clave: %d\n", nav->refslin->aux->datos2.clave);
        printf("Categoría: %s\n", nav->refslin->aux->datos2.categoria);
        printf("Producto: %s\n", nav->refslin->aux->datos2.producto);
        printf("Precio: %.2f\n", nav->refslin->aux->datos2.precio);
        printf("Inventario: %d\n\n", nav->refslin->aux->datos2.inventario);

        printf("Opciones:\n");
        printf("a) Anterior   b) Regresar al menú   c) Agregar al carrito   d) Siguiente   e) Salir del programa\n");
        printf("Seleccione una opción: ");
        scanf(" %c", &opc);

        switch (opc) {
            case 'a':
            case 'A':
                flag = 0;
                if (nav->refslin->aux->izq == NULL) {
                    printf("\nInicio de la lista. Ya no hay más elementos\n\n");
                } else {
                    nav->refslin->aux = nav->refslin->aux->izq;
                    system("clear");
                }
                break;
            case 'd':
            case 'D':
                flag = 0;
                if (nav->refslin->aux->der == NULL) {
                    printf("Fin de la lista.\n\n");
                } else {
                    nav->refslin->aux = nav->refslin->aux->der;
                    system("clear");
                }
                break;
            case 'b':
            case 'B':
                flag = 1;
                system("clear");
                break;
            case 'c':
            case 'C':
                flag = 0;
                if (nav->refslin->aux->datos2.inventario == 0) {
                    printf("Este producto no está disponible por el momento.\n\n");
                } else {
                    system("clear");
                    agregarCarrito2(nav);
                }
                system("clear");
                break;
            case 'e':
            case 'E':
                printf("¿Desea salir completamente del programa?, se borrarán los productos guardados en el carrito. (s/n) \n");
                scanf(" %c", &opc);
                if (opc == 's' || opc == 'S') {
                    exit(1);
                }
                system("clear");
                break;
            default:
                printf("Opción no válida. Por favor, seleccione una opción del menú.\n");
        }
    }

    return;
}

int ticket(nav *nav)
{
    FILE *fp;
    float precTot = 0.0;
    int artTot = 0, i = 1; 
    char nomArch[100];
    static int ticket_number = 0; 

    ticket_number++;
    sprintf(nomArch, "ticket_%i.txt", ticket_number);

    fp = fopen(nomArch, "w");
    if(fp == NULL)
    {
        printf("\nArchivo no disponible.\n");
        exit(1);
    }
    if(nav->iniciocar == NULL)
    {
        printf("\nCarrito vacío.\n");
    }
    else
    {
        printf("\nTu ticket es el siguiente: \n");
        printf("\n------------------------------------------------------------------------\n");
        fprintf(fp, "\n------------------------------------------------------------------------\n");
        printf("CANTIDAD\tPRODUCTO\tPRECIO\n");
        fprintf(fp, "CANTIDAD\tPRODUCTO\tPRECIO\n");
        printf("\n------------------------------------------------------------------------\n");
        fprintf(fp, "\n------------------------------------------------------------------------\n");
        while(nav->iniciocar != NULL)
        {
            printf("%d\t%s\t$%f\n", nav->iniciocar->datos.cantidad, nav->iniciocar->datos.producto, nav->iniciocar->datos.precio);
            fprintf(fp, "%d\t%s\t$%f\n", nav->iniciocar->datos.cantidad, nav->iniciocar->datos.producto, nav->iniciocar->datos.precio);
            precTot += (nav->iniciocar->datos.precio * nav->iniciocar->datos.cantidad);
            artTot += nav->iniciocar->datos.cantidad;
            deQueue(&nav->iniciocar, &nav->fincar);            
        }
        printf("------------------------------------------------------------------------\n");
        fprintf(fp, "\n------------------------------------------------------------------------\n");
        printf("%d productos:\n", artTot);
        fprintf(fp, "%d productos:\n", artTot);
        printf("Subtotal: $%f\n", precTot);
        fprintf(fp, "Total: $%f\n", precTot);
        printf("------------------------------------------------------------------------\n");
        fprintf(fp, "\n------------------------------------------------------------------------\n");
    }
    fclose(fp);

    return ticket_number;
}

void crearBin(refs refscirc, refs refslin)
{
    FILE *fp;
    nodo *actual1;
    nodo *actual2;

    actual1 = refscirc.inicio;
    actual2 = refslin.inicio;

    fp = fopen("inventario.bin", "wb");
    if(fp == NULL)
    {
        printf("\nArchivo no disponible.\n");
        exit(1);
    }

    if(actual1 == NULL)
    {
        printf("\nNo hay elementos en la categoría 1 para escribir en el archivo.\n");
    }
    else
    {
        do
        {
            fwrite(&(actual1->datos1), sizeof(cat1), 1, fp);
            actual1 = actual1->der;
        } while(actual1 != refscirc.inicio);
    }

    if(actual2 == NULL)
    {
        printf("\nNo hay elementos en la categoría 2 para escribir en el archivo.\n");
    }
    else
    {
        while(actual2 != NULL)
        {
            fwrite(&(actual2->datos2), sizeof(cat2), 1, fp);
            actual2 = actual2->der;
        }
    }

    fclose(fp);

    return;
}

void borrarTodoCarrito(nav *nav)
{
    if(nav->iniciocar == NULL)
    {
        printf("\nCarrito vacío.\n");
    }
    else
    {   
        while(nav->iniciocar != NULL)
        {
            printf("Borrando producto: %s\n", nav->iniciocar->datos.producto); // Impresión de depuración
            if(strcmp(nav->refscirc->aux->datos1.categoria, nav->iniciocar->datos.categoria) == 0)
            {
                do {
                    if(strcmp(nav->refscirc->inicio->datos1.producto, nav->iniciocar->datos.producto) == 0) 
                    {
                        nav->refscirc->inicio->datos1.inventario += nav->iniciocar->datos.cantidad;
                        break;
                    }
                    nav->refscirc->inicio = nav->refscirc->inicio->der;
                } while(nav->refscirc->inicio != nav->refscirc->inicio);
            }
            else if(strcmp(nav->refslin->inicio->datos2.categoria, nav->iniciocar->datos.categoria) == 0)
            {
                if(nav->refscirc->inicio == nav->refscirc->inicio) 
                {
                    while(nav->refslin->inicio != NULL) 
                    {
                        if(strcmp(nav->refslin->inicio->datos2.producto, nav->iniciocar->datos.producto) == 0) 
                        {
                            nav->refslin->inicio->datos2.inventario += nav->iniciocar->datos.cantidad;
                            break;
                        }
                        nav->refslin->inicio = nav->refslin->inicio->der;
                    }
                }
            }
            deQueue(&nav->iniciocar, &nav->fincar);            
        }
        printf("Todos los productos han sido borrados del carrito.\n");
    }

    return;
}

void borrarProducto(nav *nav)
{
    if(nav->iniciocar == NULL && nav->fincar == NULL)
    {
        printf("\nNo se puede eliminar una cola vacía.\n");
        return;
    }
    else if(nav->iniciocar == nav->fincar)
    {
        deQueue(&nav->iniciocar, &nav->fincar);            
        printf("\nProducto eliminado del carrito.\n");
        nav->iniciocar = NULL; 
        nav->fincar = NULL;
        return;
    }
    else if(nav->iniciocar != nav->fincar)
    {
        deQueue(&nav->iniciocar, &nav->fincar);            
        printf("\nProducto eliminado del carrito.\n");
    }

    return;
}

void editarCantidad(nav *nav)
{
    int nuevaCantidad, temp;
    nodocar *actual = nav->iniciocar;
    nodo *aux;
    
    printf("Dame la nueva cantidad que deseas: ");
    scanf("%d", &nuevaCantidad);

    if (actual == NULL) {
        printf("\nCarrito vacío.\n");
        return;
    }

    if (nuevaCantidad < 0) {
        printf("\nLa cantidad no puede ser negativa.\n");
        return;
    }

    if (nuevaCantidad == 0) {
        printf("\nCantidad modificada a 0. El producto se eliminará del carrito.\n");
        borrarProducto(nav);
        return;
    }

    while(actual != NULL)
    {
        if(strcmp(nav->refscirc->inicio->datos1.categoria, actual->datos.categoria) == 0)
        {
            aux = nav->refscirc->inicio;
            do {
                if (strcmp(aux->datos1.producto, actual->datos.producto) == 0) 
                {
                    if (nav->refscirc->inicio->datos1.inventario < nuevaCantidad)
                    {   
                        printf("\nNo hay suficiente inventario para hacer esta modificación.\n");
                        return;
                    }
                }
                aux = aux->der;
            } while(aux != nav->refscirc->inicio);
        }
        else if (strcmp(nav->refslin->inicio->datos2.categoria, actual->datos.categoria) == 0)
        {
            aux = nav->refslin->inicio;
            while (aux != NULL) 
            {
                if (strcmp(aux->datos2.producto, actual->datos.producto) == 0) 
                {
                    if (nav->refscirc->inicio->datos2.inventario < nuevaCantidad)
                    {   
                        printf("\nNo hay suficiente inventario para hacer esta modificación.\n");
                        return;
                    }
                }
                aux = aux->der;
            }
        }
        actual = actual->next;
    }

    actual = nav->iniciocar;

    while(actual != NULL)
    {
        if (actual->datos.cantidad > nuevaCantidad) 
        {
            // Aumentar el inventario si disminuye la cantidad en el carrito
            temp = actual->datos.cantidad - nuevaCantidad;
            actual->datos.cantidad = nuevaCantidad;
            // Actualizar el inventario antes de borrar el producto del carrito
            if (strcmp(nav->refscirc->inicio->datos1.categoria, actual->datos.categoria) == 0)
            {
                aux = nav->refscirc->inicio;
                do {
                    if (strcmp(aux->datos1.producto, actual->datos.producto) == 0) 
                    {
                        if (aux->datos1.inventario == 0)
                        {   
                            printf("\nLa cantidad de este producto en el inventario es cero.\n");
                            break;
                        }
                        aux->datos1.inventario += temp; 
                        break;
                    }
                    aux = aux->der;
                } while(aux != nav->refscirc->inicio);
            }
            else if (strcmp(nav->refslin->inicio->datos2.categoria, actual->datos.categoria) == 0)
            {
                aux = nav->refslin->inicio;
                while (aux != NULL) 
                {
                    if (strcmp(aux->datos2.producto, actual->datos.producto) == 0) 
                    {
                        if (aux->datos2.inventario == 0)
                        {   
                            printf("\nLa cantidad de este producto en el inventario es cero.\n");
                            break;
                        }
                        aux->datos2.inventario += temp; 
                        break;
                    }
                    aux = aux->der;
                }
            }            
            break;
        } 
        else if (actual->datos.cantidad < nuevaCantidad) 
        {
            // Reducir el inventario si aumenta la cantidad en el carrito
            temp = nuevaCantidad - actual->datos.cantidad;
            actual->datos.cantidad = nuevaCantidad;
            if (strcmp(nav->refscirc->inicio->datos1.categoria, actual->datos.categoria) == 0)
            {
                aux = nav->refscirc->inicio;
                do {
                    if (strcmp(aux->datos1.producto, actual->datos.producto) == 0) 
                    {
                        if (aux->datos1.inventario == 0)
                        {   
                            printf("\nLa cantidad de este producto en el inventario es cero.\n");
                            break;
                        }
                        aux->datos1.inventario -= temp; 
                        break;
                    }
                    aux = aux->der;
                } while(aux != nav->refscirc->inicio);
            }
            else if (strcmp(nav->refslin->inicio->datos2.categoria, actual->datos.categoria) == 0)
            {
                aux = nav->refslin->inicio;
                while (aux != NULL) 
                {
                    if (strcmp(aux->datos2.producto, actual->datos.producto) == 0) 
                    {
                        if (aux->datos2.inventario == 0)
                        {   
                            printf("\nLa cantidad de este producto en el inventario es cero.\n");
                            break;
                        }
                        aux->datos2.inventario -= temp; 
                        break;
                    }
                    aux = aux->der;
                }
            }            
            break;
        } 
        else 
        {
            actual = actual->next;
        }
    }

    return;
}

void modificarCarrito(nav *nav) 
{
    nodocar *aux;
    char opc;
    int flag = 0;

    aux = nav->iniciocar;

    if (nav->iniciocar == NULL) {
        printf("\nCarrito vacío.\n");
    } else {
        do {
            system("clear"); 

            printf("----- Carrito de Compras -----\n");
            printf("Categoría: %s\n", aux->datos.categoria);
            printf("Producto: %s\n", aux->datos.producto);
            printf("Precio: %.2f\n", aux->datos.precio);
            printf("Cantidad: %d\n\n", aux->datos.cantidad);

            printf("Opciones:\n");
            printf("a) Ir al inicio del carrito c) Modificar cantidad   d) Siguiente\n");
            printf("b) Regresar al menú   e) Salir del programa   g) Borrar todo el carrito\n");
            printf("Seleccione una opción: ");
            scanf(" %c", &opc);

            switch (opc) {
                case 'a':
                case 'A':
                    flag = 0;
                    if (aux == nav->iniciocar) {
                        printf("Inicio del carrito.\n\n");
                    } else {
                        aux = nav->iniciocar;
                        system("clear");
                    }
                    break;
                case 'd':
                case 'D':
                    flag = 0;
                    if (aux->next == NULL) {
                        system("clear");
                        getchar();
                        printf("\nHaz llegado al fin del carrito, selecciona la opción a) para regresar al inicio.\n\n");
                        getchar();
                        system("clear");
                    } else {
                        aux = aux->next;
                        system("clear");
                    }
                    break;
                case 'b':
                case 'B':
                    flag = 1;
                    break;
                case 'e':
                case 'E':
                    system("clear");
                    printf("¿Desea salir completamente del programa?, se borrarán los productos guardados en el carrito. (s/n) \n");
                    scanf(" %c", &opc);
                    if (opc == 's' || opc == 'S') 
                    {
                        borrarTodoCarrito(nav);
                        system("clear");
                        exit(1);
                    }
                    break;
                case 'c':
                case 'C':
                    editarCantidad(nav);
                    flag = 0;
                    break;
                case 'g':
                case 'G':
                    system("clear");
                    borrarTodoCarrito(nav);
                    break;
                default:
                    printf("Opción no válida. Por favor, seleccione una opción del menú.\n");
            }
        } while (flag == 0);
    }

    return;
}

extern void navegar(nav *nav) 
{
    char opcion, opcar;
    int bandera, i;

    bandera = 0;

    do {
        printf("\n*** Menú Principal ***\n");
        printf("1. Visualizar categoría 1\n");
        printf("2. Visualizar categoría 2\n");
        printf("3. Comprar\n");
        printf("4. Ver o modificar carrito\n");
        printf("5. Salir\n");

        printf("Seleccione una opción: ");
        scanf(" %c", &opcion);

        switch (opcion) {
            case '1':
                navegarCategoria1(nav);
                break;
            case '2':
                navegarCategoria2(nav);
                break;
            case '3':
                mostrarCarrito(nav->iniciocar);
                printf("\nSeleccione:\n");
                printf("A. Finalizar compra\n");
                printf("B. Modificar carrito\n");
                scanf(" %c", &opcar);
                if (opcar == 'A' || opcar == 'a') {
                    i = ticket(nav);
                    crearBin(*(nav->refscirc), *(nav->refslin));
                } else if (opcar == 'B' || opcar == 'b') {
                    modificarCarrito(nav);
                }
                break;
            case '4':
                modificarCarrito(nav);
                break;
            case '5':
                printf("Ha realizado %i compras.\n", i);
                if (i > 0) {
                    printf("Los tickets se han guardado en su carpeta.\n");
                }
                printf("¿Desea salir completamente del programa? (s/n)\n");
                scanf(" %c", &opcion);
                if (opcion == 's' || opcion == 'S') {
                    exit(1);
                }
                break;
            default:
                printf("Opción no válida. Por favor, seleccione una opción del menú.\n");
        }
    } while (bandera == 0);

    return;
}
