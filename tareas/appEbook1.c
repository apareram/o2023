/*
@file appEbook.c
@brief  El programa es una aplicación de interfaz gráfica construida con GTK en C para la creación y edición de libros electrónicos (ebooks). 
        A través de varias ventanas y botones, el usuario puede realizar acciones como crear un nuevo libro, editar un libro existente, nombrar secciones, 
        escribir contenido, y guardar el libro en formatos binarios y de texto. La aplicación utiliza callbacks para manejar eventos de botones y 
        realiza diversas funciones relacionadas con la manipulación y gestión de libros electrónicos.
@author Alberto Parera Méndez, Diego Altamirano Tovar Y Ariadna Berenice Pedraza Rodriguez.
@date 28/11/2023
*/

#include "tiposGTK.h"

gboolean delete_event_handler(GtkWidget *widget, GdkEvent *event, gpointer user_data);
void closeTheApp(GtkWidget *botSalir, gpointer data);
void regresarAVentanaAnterior(GtkWidget *botRegresar, gpointer pVentana);
void visualizarVentanaSiguiente(GtkWidget *botCrear, gpointer pVentana);
void tomarTexto(GtkButton *was_clicked, gpointer *pmiApp);
void crearTodo(GtkWidget *n, gpointer *pmiApp);
void nombrarSecciones(GtkWidget *n, gpointer *pmiApp);
void guardarEnBin(GtkWidget *was_clicked, gpointer *pmiApp);
void guardarEnTxt(GtkWidget *was_clicked, gpointer *pmiApp);
void siguientePagina(GtkWidget *was_clicked, gpointer *pmiApp);
void mostrarLibro(Aplicacion* app);
void siguienteLibro(GtkWidget* widget, gpointer data);
void anteriorLibro(GtkWidget* widget, gpointer data);
void continuarLectura(GtkWidget* widget, gpointer data);


int main(int argc, char *argv[])
{
    refsApp miApp;
    GtkWidget *window1, *window2, *window3, *window4, *window5, *window6, *window7;
    GtkWidget *bienvenidoLbl, *introLbl;
    GtkWidget *botEditar, *botCrear, *botSalir;
    GtkWidget *hBox1, *vBox1;
   
    Libro libro1 = { "Libro 1", NULL, NULL };
    Libro libro2 = { "Libro 2", NULL, &libro1 };
    Libro libro3 = { "Libro 3", NULL, &libro2 };
    

   
    Aplicacion app;
    app.inicio = &libro1;
    app.libroActual = app.inicio;
 

    // Inicializar entorno GTK
    gtk_init(&argc, &argv);

    // Ventana principal
    window1 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    hBox1 = gtk_hbox_new(FALSE, 10);
    vBox1 = gtk_vbox_new(FALSE, 10);
    botEditar = gtk_button_new_with_label("Editar Libro");
    botCrear = gtk_button_new_with_label("Crear Libro");
    botSalir = gtk_button_new_with_label("Salir");
    bienvenidoLbl = gtk_label_new("Bienvenido");
    introLbl = gtk_label_new("Con esta app puedes crear un libro o editar un libro existente");

   

    app.ventana = gtk_window_new(GTK_WINDOW_TOPLEVEL);
 

   
    g_signal_connect(G_OBJECT(app.btnSiguiente), "clicked", G_CALLBACK(siguienteLibro), &app);
    g_signal_connect(G_OBJECT(app.btnAnterior), "clicked", G_CALLBACK(anteriorLibro), &app);
    g_signal_connect(G_OBJECT(app.btnContinuar), "clicked", G_CALLBACK(continuarLectura), &app);

  
    GtkWidget* vbox = gtk_vbox_new(TRUE, 5);
    gtk_box_pack_start(GTK_BOX(vbox), app.labelTitulo, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), app.btnSiguiente, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), app.btnAnterior, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), app.btnContinuar, TRUE, TRUE, 0);
    gtk_container_add(GTK_CONTAINER(app.ventana), vbox);

  
    gtk_widget_show_all(window7);
    gtk_widget_show_all(app.ventana);
    gtk_widget_show_all(window1);

    gtk_main();

    return 0; 
}
