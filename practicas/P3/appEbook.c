#include "tiposGTK.h"

gboolean delete_event_handler(GtkWidget *widget, GdkEvent *event, gpointer user_data);
void closeTheApp(GtkWidget *botSalir, gpointer data);
/*
void visualizarVentanaEditar(GtkWidget *botEditar, gpointer pVentana);
void visualizarVentanaCrear(GtkWidget *botCrear, gpointer pVentana);

void print_and_quit(GtkButton *was_clicked, gpointer user_data);
void on_insert_text(GtkTextBuffer *buffer, GtkTextIter *location, gchar *text, gint len, gpointer data);
*/

int main(int argc, char *argv[]) 
{
    refsApp miApp;
    GtkWidget *window1, *window2, *window3, *window4, *window5;
    GtkWidget *bienvenidoLbl, *introLbl;
    GtkWidget *botEditar, *botCrear, *botSalir;
    GtkWidget *hBox1, *vBox1;    

    //1. inicializar entorno
    gtk_init(&argc, &argv);

    //2. crear los widgets
    window1 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    hBox1 = gtk_hbox_new(FALSE, 10);
    vBox1 = gtk_vbox_new(FALSE, 10);
    botEditar = gtk_button_new_with_label("Editar Libro");
    botCrear = gtk_button_new_with_label("Crear Libro");
    botSalir = gtk_button_new_with_label("Salir");
    bienvenidoLbl = gtk_label_new("Bienvenido");
    introLbl = gtk_label_new("Con esta app puedes crear un libro o editar un libro existente");

    gtk_window_set_title(GTK_WINDOW(window1), "Mascotas");
    gtk_container_set_border_width(GTK_CONTAINER(window1), 100);

    //3. Registro de callbacks
    g_signal_connect(G_OBJECT(window1), "delete_event", G_CALLBACK(delete_event_handler), NULL);
    g_signal_connect(G_OBJECT(botSalir), "clicked", GTK_SIGNAL_FUNC(closeTheApp), NULL);

    //g_signal_connect(G_OBJECT(botEditar), "clicked", GTK_SIGNAL_FUNC(visualizarVentanaEditar), window2);
    //g_signal_connect(G_OBJECT(botCrear), "clicked", GTK_SIGNAL_FUNC(visualizarVentanaCrear), window3);

    //4. Definiendo jerarquias
    gtk_box_pack_start_defaults(GTK_BOX(vBox1), bienvenidoLbl);
    gtk_box_pack_start_defaults(GTK_BOX(vBox1), introLbl);
    gtk_box_pack_start_defaults(GTK_BOX(hBox1), botEditar);
    gtk_box_pack_start_defaults(GTK_BOX(hBox1), botCrear);
    gtk_box_pack_start_defaults(GTK_BOX(vBox1), hBox1);
    gtk_box_pack_start_defaults(GTK_BOX(hBox1), botSalir);
    gtk_container_add(GTK_CONTAINER(window1), vBox1);

    //5. Mostrar los widgets
    gtk_widget_show_all(window1);

    //6. El programa se queda en loop
    gtk_main();


    return 0; 
}