#include "defGTK.h"

arbolIMC *insertarYcalcular(char inNom[], float inPeso, float inEstatura, arbolIMC *raiz);
void imprimirIMC(refsApp *refs);
void imprimirEnOrden(arbolIMC *raiz);

extern gboolean delete_event_handler(GtkWidget *widget, GdkEvent *event, gpointer user_data)
{
    refsApp *refs;
    arbolIMC *root;
    
    refs = (refsApp *)user_data;

    root = refs->raiz;

    imprimirEnOrden(root);

    gtk_main_quit();

    return(FALSE); 
}

extern void closeTheApp(GtkWidget *botSalir, gpointer data)
{
    refsApp *refs;
    arbolIMC *root;
    
    refs = (refsApp *)data;

    root = refs->raiz;

    imprimirEnOrden(root);

    gtk_main_quit();

    return;
}

void calcularEinsertar(GtkWidget *botCrear, gpointer pmiApp)
{
    refsApp *refs;
    
    refs = (refsApp *)pmiApp;

    float inPeso, inEstatura;
    char inNom[100];

    strcpy(inNom, gtk_entry_get_text(GTK_ENTRY(refs->nombre)));
    sscanf(gtk_entry_get_text(GTK_ENTRY(refs->peso)), "%f", &inPeso);
    sscanf(gtk_entry_get_text(GTK_ENTRY(refs->estatura)), "%f", &inEstatura);

    refs->raiz =insertarYcalcular(inNom, inPeso, inEstatura, refs->raiz);
    imprimirIMC(refs);
    gtk_label_set_text(GTK_LABEL(refs->diagnosticosLbl), refs->diag);

    return;
}

void imprimir(GtkWidget *botCrear, gpointer pmiApp)
{
    refsApp *refs;
    arbolIMC *root;
    
    refs = (refsApp *)pmiApp;

    root = refs->raiz;

    imprimirEnOrden(root);

    return;
}
