/*
@file appIMC.c
@brief Se requiere la sigiente aplicacion en TK que permite realizar el calculo del IMC de personas que son clientes de una clinica.
       Haga la interfaz grafica que realice los calculos y muestre los resultados del IMC con su diagnostico en la App; por cada IMC
       que ccalcule de un paciente, debe de almacenar temporalmente en una estructura de datos de arbol binario los resultados el IMC 
       y los datos de cada paciente. 
@authors Alberto Parera, Diego Tovar  y Ariadna Pedraza
@date 30/2023
*/
#include "defGTK.h"

gboolean delete_event_handler(GtkWidget *widget, GdkEvent *event, gpointer user_data);
void closeTheApp(GtkWidget *botSalir, gpointer data);
void calcularEinsertar(GtkWidget *botCrear, gpointer pmiApp);
void imprimir(GtkWidget *botCrear, gpointer pmiApp);

/*
@brief El main tiliza la biblioteca GTK para crear una interfaz gráfica de usuario que permite calcular el Índice de Masa Corporal (IMC). 
@author Alberto Parera, Diego Tovar y Ariadna Pedraza 
@date 30/11/2023
@param int argc: Representa el número de argumentos de la línea
@param char *argv[]: Es un array de cadenas que contiene los argumentos de la línea de comandos.
*/

int main(int argc, char *argv[]) 
{
    refsApp miApp;
    char cadDiag[60];
    GtkWidget *window;
    GtkWidget *nomLbl, *pesoLbl, *estaturaLbl, *diagnosticoLbl;
    GtkWidget *botCalcularEinsertar, *botSalir;
    GtkWidget *hBox1, *hBox11, *hBox12, *hBox13, *hBox14, *hBox15, *vBox1;    

    miApp.raiz = NULL;

    strcpy(cadDiag, "Aquí se mostraran los diagnósticos.");
    strcpy(miApp.diag, cadDiag);

    //1. inicializar entorno
    gtk_init(&argc, &argv);

    //2. crear los widgets
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    hBox1 = gtk_hbox_new(FALSE, 10);
    hBox11 = gtk_hbox_new(FALSE, 10);
    hBox12 = gtk_hbox_new(FALSE, 10);
    hBox13 = gtk_hbox_new(FALSE, 10);
    hBox14 = gtk_hbox_new(FALSE, 10);
    hBox15 = gtk_hbox_new(FALSE, 10);
    vBox1 = gtk_vbox_new(FALSE, 10);
    botCalcularEinsertar = gtk_button_new_with_label("Calcular e insertar nodo");
    botSalir = gtk_button_new_with_label("Salir");
    nomLbl = gtk_label_new("Nombre:");
    pesoLbl = gtk_label_new("Peso en kgs:");
    estaturaLbl = gtk_label_new("Estatura en mts:");
    miApp.nombre = gtk_entry_new();
    miApp.peso = gtk_entry_new();
    miApp.estatura = gtk_entry_new();
    miApp.diagnosticosLbl = gtk_label_new(miApp.diag);

    gtk_window_set_title(GTK_WINDOW(window), "APP IMC");
    gtk_container_set_border_width(GTK_CONTAINER(window), 100);

    //3. Registro de callbacks
    g_signal_connect(G_OBJECT(window), "delete_event", G_CALLBACK(delete_event_handler), &miApp);
    g_signal_connect(G_OBJECT(botSalir), "clicked", GTK_SIGNAL_FUNC(closeTheApp), &miApp);
    g_signal_connect(G_OBJECT(botCalcularEinsertar), "clicked", GTK_SIGNAL_FUNC(calcularEinsertar), &miApp);
    g_signal_connect(G_OBJECT(botSalir), "clicked", GTK_SIGNAL_FUNC(imprimir), &miApp);


    //4. Definiendo jerarquias
    gtk_box_pack_start_defaults(GTK_BOX(hBox1), nomLbl);
    gtk_box_pack_start_defaults(GTK_BOX(hBox1), miApp.nombre);
    gtk_box_pack_start_defaults(GTK_BOX(vBox1), hBox1);
    gtk_box_pack_start_defaults(GTK_BOX(hBox11), pesoLbl);
    gtk_box_pack_start_defaults(GTK_BOX(hBox11), miApp.peso);
    gtk_box_pack_start_defaults(GTK_BOX(vBox1), hBox11);
    gtk_box_pack_start_defaults(GTK_BOX(hBox12), estaturaLbl);
    gtk_box_pack_start_defaults(GTK_BOX(hBox12), miApp.estatura);
    gtk_box_pack_start_defaults(GTK_BOX(vBox1), hBox12);
    gtk_box_pack_start_defaults(GTK_BOX(hBox13), botCalcularEinsertar);
    gtk_box_pack_start_defaults(GTK_BOX(vBox1), hBox13);
    gtk_box_pack_start_defaults(GTK_BOX(hBox14),botSalir);
    gtk_box_pack_start_defaults(GTK_BOX(vBox1), hBox14);
    gtk_box_pack_start_defaults(GTK_BOX(vBox1), miApp.diagnosticosLbl);
    gtk_container_add(GTK_CONTAINER(window), vBox1);


    //5. Mostrar los widgets
    gtk_widget_show_all(window);

    //6. El programa se queda en loop
    gtk_main();

    return 0; 
}