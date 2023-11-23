#include "defTiposGTK.h"

void insertarCola(tipoMascota dat1, refsApp *pMiApp);
void imprimirListaDobleCirc(refsApp pMiApp);
void moverIzq(refsApp *pRefs);
void moverDer(refsApp *pRefs);

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

extern void darAltaMascota(GtkWidget *pBotInsertar, gpointer pMiApp)
{
    refsApp *refs; 
    tipoMascota datos;

    refs = (refsApp *)pMiApp;

    strcpy(datos.raza, gtk_entry_get_text(GTK_ENTRY(refs->inRaza)));
    sscanf(gtk_entry_get_text(GTK_ENTRY(refs->inCliente)), "%d", &datos.cliente);
    sscanf(gtk_entry_get_text(GTK_ENTRY(refs->inPeso)), "%f", &datos.peso);

    insertarCola(datos, refs);
    system("clear");
    imprimirListaDobleCirc(*refs);

    return;
}

extern void recorrerIzq(GtkWidget *pBotIzq, gpointer pMiApp)
{
    refsApp *refs; 
    tipoMascota datos;
    char cliente[10], peso[10];

    refs = (refsApp *)pMiApp;

    moverIzq(refs);

    sprintf(cliente, "%d", refs->aux->datos.cliente);
    gtk_label_set_text(GTK_LABEL(refs->clienteLbl), cliente);
    gtk_label_set_text(GTK_LABEL(refs->razaLbl), refs->aux->datos.raza);
    sprintf(peso, "%f", refs->aux->datos.peso);
    gtk_label_set_text(GTK_LABEL(refs->pesoLbl), peso);

    return;
}

extern void recorrerDer(GtkWidget *pBotDer, gpointer pMiApp)
{
    refsApp *refs; 
    tipoMascota datos;
    char cliente[10], peso[10];

    refs = (refsApp *)pMiApp;

    moverDer(refs);

    sprintf(cliente, "%d", refs->aux->datos.cliente);
    gtk_label_set_text(GTK_LABEL(refs->clienteLbl), cliente);
    gtk_label_set_text(GTK_LABEL(refs->razaLbl), refs->aux->datos.raza);
    sprintf(peso, "%f", refs->aux->datos.peso);
    gtk_label_set_text(GTK_LABEL(refs->pesoLbl), peso);

    return;
}