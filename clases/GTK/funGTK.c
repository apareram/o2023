/*
@file gunGTK.c
@brief En este archivo están los callbacks que utiliza el ejemplo ventana.c
@date 9/nov/2023
@author ejemplo modificado del libro Krause.
*/

#include <gtk-2.0/gtk/gtk.h>

/*
@brief Esta función es un callback que tiene asociada el objeto botón. Si se da el evento de click,
       se ejecuta un comando para terminar y ensegida se ejecuta una fiunción que termina la app o 
       el proceso de la aplicación ventana.c.
@date 9/nov/2023
@author ejemplo modificado del libro Krause.
@param *was_clicked es un apuntador a un Widget de botón.
@param 
*/
extern void print_and_quit(GtkButton *was_clicked, gpointer user_)
{
    /*Use glibs printf pequvalent ti print a message*/
    /* 7. Aquí se da la condición de fin de programa*/
    g_print("Gracias por usarme.\n");
    gtk_main_quit(1);

    return;
}

gboolean delete_event_handler(GtkWidget *widget, GdkEvent *event, gpointer user_data)
{
    /* Recibe cierre de ventana del window manager */
    g_print("El window manager está preguntando por cerrar esta aplicación\n");
    return(FALSE); /* FALSE no previene de cierre*/
}
/* Recibe cierre de ventana del window manager */
g_print("El window manager está preguntando por cerrar esta aplicación\n");
return(FALSE); /* FALSE no previene de cierre*/