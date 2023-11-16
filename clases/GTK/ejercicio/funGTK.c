#include "defTiposGTK.h"

extern gboolean delete_event_handler(GtkWidget *widget, GdkEvent *event, gpointer user_data)
{
    gtk_main_quit();

    return(FALSE); // false propaga el evento
}

void closeTheApp(GtkWidget *botSalir, gpointer data)
{
    gtk_main_quit();

    return;
}
