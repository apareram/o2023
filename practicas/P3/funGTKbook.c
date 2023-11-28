#include "tiposGTK.h"

void instertarTodo(char tituloLibro[], int numeroSeccion, refsApp *refs);
void imprimirRepisa(refsApp refs);
void modificarNomSeccion(rep *libro, char nomSecc[]);
void guardarLibroEnBin(rep *libro);
void guardarLibroEnTxt(rep *libro);
void moverPagina(rep *libro);
void siguienteSec(rep *libro);

extern gboolean delete_event_handler(GtkWidget *widget, GdkEvent *event, gpointer user_data)
{
    gtk_main_quit();

    return(FALSE); 
}

extern void closeTheApp(GtkWidget *botSalir, gpointer data)
{
    gtk_main_quit();

    return;
}

extern void regresarAVentanaAnterior(GtkWidget *botRegresar, gpointer pVentana)
{
    gtk_widget_hide(gtk_widget_get_toplevel(botRegresar)); 
    gtk_widget_show_all(pVentana); 
}

extern void visualizarVentanaCrear(GtkWidget *botAlta, gpointer pVentana)
{
    gtk_widget_hide(gtk_widget_get_toplevel(botAlta));
    gtk_widget_show_all(pVentana);

    return;
}

extern void visualizarVentanaEditar(GtkWidget *botAlta, gpointer pVentana)
{
    gtk_widget_hide(gtk_widget_get_toplevel(botAlta));
    gtk_widget_show_all(pVentana);

    return;
}

extern void visualizarVentanaAviso(GtkWidget *botAlta, gpointer pVentana)
{
    gtk_widget_hide(gtk_widget_get_toplevel(botAlta));
    gtk_widget_show_all(pVentana);

    return;
}

extern void visualizarVentanaSecc(GtkWidget *botAlta, gpointer pVentana)
{
    gtk_widget_hide(gtk_widget_get_toplevel(botAlta));
    gtk_widget_show_all(pVentana);

    return;
}

extern void visualizarVentanaEscribir(GtkWidget *botAlta, gpointer pVentana)
{
    gtk_widget_hide(gtk_widget_get_toplevel(botAlta));
    gtk_widget_show_all(pVentana);

    return;
}

extern void crearTodo(GtkWidget *n, gpointer *pmiApp)
{
    refsApp *refs;
    
    refs = (refsApp *)pmiApp;

    int numeroSeccion;
    char tituloLibro[40];

    strcpy(tituloLibro, gtk_entry_get_text(GTK_ENTRY(refs->titulo)));
    sscanf(gtk_entry_get_text(GTK_ENTRY(refs->numSecc)), "%d", &numeroSeccion);

    instertarTodo(tituloLibro, numeroSeccion, refs);

    imprimirRepisa(*refs);

    return;
}

extern void nombrarSecciones(GtkWidget *n, gpointer *pmiApp)
{   
    refsApp *refs;
    char newNomSecc[40];

    refs = (refsApp *)pmiApp;

    strcpy(newNomSecc, gtk_entry_get_text(GTK_ENTRY(refs->nomSecc)));        

    modificarNomSeccion(refs->libroActual, newNomSecc);

    return;
}
void moverSeccion(GtkWidget *was_clicked, gpointer *pmiApp)
{
    refsApp *refs;
    refs = (refsApp *)pmiApp;

    siguienteSec(refs->libroActual);

    return;
}

extern void tomarTexto(GtkWidget *was_clicked, gpointer *pmiApp)
{
    refsApp *refs;
    GtkTextBuffer *buffer; 
    GtkTextIter inicio, fin; 
    const gchar *textoEnVentana;
    secc *seccionActual;
    hoja *paginaActual;

    refs = (refsApp *)pmiApp;

    if(refs->libroActual == NULL)
    {
        printf("\no un un libro actualmente en edición\n");
        return;
    }

    seccionActual = refs->libroActual->inicio;
    paginaActual = seccionActual->primPag;
    while (paginaActual != NULL) 
    {
        paginaActual = paginaActual->next;
    }

    buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(refs->texto));
    gtk_text_buffer_get_bounds(GTK_TEXT_BUFFER(buffer), &inicio, &fin);
    textoEnVentana = gtk_text_buffer_get_text(GTK_TEXT_BUFFER(buffer), &inicio, &fin, FALSE); 

    strncpy(paginaActual->texto, textoEnVentana, sizeof(paginaActual->texto) - 1);
    paginaActual->texto[sizeof(paginaActual->texto) - 1] = '\0';

}

extern void guardarEnBin(GtkWidget *was_clicked, gpointer *pmiApp)
{
    refsApp *refs;
    refs = (refsApp *)pmiApp;

    if(refs->libroActual == NULL)
    {
        printf("\no un un libro actualmente en edición\n");
        return;
    }

    guardarLibroEnBin(refs->libroActual);
}

extern void guardarEnTxt(GtkWidget *was_clicked, gpointer *pmiApp)
{
    refsApp *refs;
    refs = (refsApp *)pmiApp;

    if(refs->libroActual == NULL)
    {
        printf("\no un un libro actualmente en edición\n");
        return;
    }

    guardarLibroEnTxt(refs->libroActual);
}

extern void siguientePagina(GtkWidget *was_clicked, gpointer *pmiApp)
{   
    refsApp *refs;
    refs = (refsApp *)pmiApp;

    moverPagina(refs->libroActual);

    return;
}