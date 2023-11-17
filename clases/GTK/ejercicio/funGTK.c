#include "defTiposGTK.h"

void insertarCola(tipoMascota dat1, refsApp *pMiApp);
void imprimirListaDobleCirc(refsApp pMiApp);

extern gboolean delete_event_handler(GtkWidget *widget, GdkEvent *event, gpointer user_data)
{
    gtk_main_quit();

    return(FALSE); // false propaga el evento
}

extern void closeTheApp(GtkWidget *botSalir, gpointer data)
{
    gtk_main_quit();

    return;
}

extern void visualizarVentanaAlta(GtkWidget *botAlta, gpointer pVentana)
{
    gtk_widget_show_all(pVentana);

    return;
}

void darAltaMascota(GtkWidget *auxi, gpointer pMiApp)
{
    refsApp *refs; 
    tipoMascota datos;

    refs = (refsApp *)pMiApp;

    strcpy(datos.raza, gtk_entry_get_text(GTK_ENTRY(refs->inRaza)));
    sscanf(gtk_entry_get_text(GTK_ENTRY(refs->inCliente)), "%d", &datos.cliente);
    sscanf(gtk_entry_get_text(GTK_ENTRY(refs->inPeso)), "%f", &datos.peso);

    insertarCola(datos, refs);
    system(clear);
    imprimirListaDobleCirc(*refs);

    return;
}