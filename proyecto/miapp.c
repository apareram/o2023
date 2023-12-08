
#include "tiposGTK.h"


typedef struct {
    gchar* titulo;
    gchar* autor;
    gchar* contenido;  
} Book;

typedef struct {
    gchar* entry;
    gint page;
} IndexEntry;


void on_save_and_exit_clicked(GtkWidget *widget, gpointer data) {
    // Implementar la lógica para guardar y salir aquí
    gtk_main_quit();
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

   
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Lector de Libros Digitales");
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    gtk_widget_set_size_request(window, 600, 400);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    
    GtkWidget *vbox = gtk_vbox_new(FALSE, 5);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    GtkWidget *save_and_exit_button = gtk_button_new_with_label("Guardar y Salir");
    g_signal_connect(save_and_exit_button, "clicked", G_CALLBACK(on_save_and_exit_clicked), NULL);
    gtk_box_pack_end(GTK_BOX(vbox), save_and_exit_button, FALSE, FALSE, 5);

   
    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
