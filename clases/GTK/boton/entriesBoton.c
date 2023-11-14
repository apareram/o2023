#include <gtk-2.0/gtk/gtk.h>
#include <string.h>
#include <stdlib.h>

void tomaTexto(GtkWidget *boton, gpointer entry); //toma el texto del entry
void closeTheApp(GtkWidget *window, gpointer data); //acción sobre la ventana, hace algo cuan do se cierra la aplicación
void borraTexto(GtkWidget *boton, gpointer entry); //borra las entradas

int main(int argc, char *argv[])
{
    /*0. Declaración de variables */

    GtkWidget *window, *vbox, *hbox, *question, *label, *entrada, *boton;
    GtkWidget *botonLimpia;

    /*1. Inicializar el ambiente*/
    gtk_init(&argc,&argv);

    /*2. Creación de los objetos y modificación de atributos */
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title (GTK_WINDOW(window), "Ejemplo de Entry");
    gtk_container_set_border_width(GTK_CONTAINER(window),10);
    question = gtk_label_new("¿Deseas ingresar datos?");
    label = gtk_label_new("Entrada (Entry):");
    boton = gtk_button_new_with_label("Guarda");
    botonLimpia = gtk_button_new_with_label("Limpia");
    entrada = gtk_entry_new();
    /* Comando para insertar testo en el campo de entrada (Entry) */
    gtk_entry_set_text(GTK_ENTRY(entrada),"Escribe un dato..." );

    /*3. Registro de los Callbacks */
    g_signal_connect(GTK_OBJECT(window), "destroy", GTK_SIGNAL_FUNC(closeTheApp), question);
    g_signal_connect(GTK_OBJECT(boton), "clicked", GTK_SIGNAL_FUNC(tomaTexto),entrada);
    g_signal_connect(GTK_OBJECT(botonLimpia), "clicked", GTK_SIGNAL_FUNC(borraTexto), entrada);

    /* 4. Define jerarquía de instancias (pack the widgets)*/
    hbox = gtk_hbox_new(FALSE, 5); //crea una ventana //horizotal
    gtk_box_pack_start_defaults(GTK_BOX(hbox), label); //dentro de la ventana van las cajas con el texto de 2.
    gtk_box_pack_start_defaults(GTK_BOX(hbox), entrada);

    vbox = gtk_vbox_new(FALSE, 5); //nueva caja vertical que contiene la caja anterior
    gtk_box_pack_start_defaults(GTK_BOX(vbox), question); //pregunta de dar un dato
    gtk_box_pack_start_defaults(GTK_BOX(vbox), hbox);
    gtk_box_pack_start_defaults(GTK_BOX(vbox), boton); //un boton de guardar
    gtk_box_pack_start_defaults(GTK_BOX(vbox), botonLimpia); //boton de limpiar

    gtk_container_add(GTK_CONTAINER(window),vbox); // esto indica que las cajas van a estar en la ventana y le digo que muestre lo  que esta apuntando a window y lo mandas a loop esperando los eventos

    /* 5. Mostrar los widgets */
    gtk_widget_show_all(window);

    /* 6. El programa se queda en loop */
    gtk_main();

    return 0;

    }

    void tomaTexto(GtkWidget *boton, gpointer entry) //
    {
    FILE *fp;
    char datos[20];
    fp = fopen("datos.txt", "a");
    if (fp == NULL)
    {
    g_print("\nArchivo no disponible.");
    exit(1);
    }

    strcpy(datos, gtk_entry_get_text(entry));
    fprintf(fp,"%s\n",datos);
    gtk_entry_set_text(GTK_ENTRY(entry),"Guardado en archivo..." ); //pone eso en el entry
    fclose(fp);

    return;
}

void borraTexto(GtkWidget *boton, gpointer entry)
{
    gtk_entry_set_text(GTK_ENTRY(entry),"" ); //sobrescribe una cadena vacía

    return;
}

void closeTheApp(GtkWidget *window, gpointer data) //
{
    gtk_label_set_text(GTK_LABEL(data), "Vas a salir.");
    g_print("\nSalir de el ejemplo entriesBoton.c\n");
    gtk_main_quit();

    return;
}