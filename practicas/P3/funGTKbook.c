#include "tiposGTK.h"

#define MAX_CHARS 1800
#define MAX_CHARS_PER_LINE 60

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

extern void visualizarVentanaCrear(GtkWidget *botAlta, gpointer pVentana)
{
    gtk_widget_show_all(pVentana);

    return;
}

extern void visualizarVentanaEditar(GtkWidget *botAlta, gpointer pVentana)
{
    gtk_widget_show_all(pVentana);

    return;
}

extern void visualizarVentanaAviso(GtkWidget *botAlta, gpointer pVentana)
{
    gtk_widget_show_all(pVentana);

    return;
}

extern void visualizarVentanaSecc(GtkWidget *botAlta, gpointer pVentana)
{
    gtk_widget_show_all(pVentana);

    return;
}

extern void on_insert_text(GtkTextBuffer *buffer, GtkTextIter *location, gchar *text, gint len, gpointer data) 
{
    GtkTextIter start, end;
    gtk_text_buffer_get_bounds(buffer, &start, &end);
    gchar *current_text = gtk_text_buffer_get_text(buffer, &start, &end, FALSE);

    if (strlen(current_text) + len > MAX_CHARS) {
        g_signal_stop_emission_by_name(buffer, "insert-text");
    }

    g_free(current_text);

    // Check for line length
    GtkTextIter line_start = *location;
    gtk_text_iter_set_line_offset(&line_start, 0);
    gchar *line_text = gtk_text_buffer_get_text(buffer, &line_start, location, FALSE);

    if (strlen(line_text) + len > MAX_CHARS_PER_LINE) {
        g_signal_stop_emission_by_name(buffer, "insert-text");
    }

    g_free(line_text);
}

extern void print_and_quit(GtkButton *was_clicked, gpointer user_data);
gboolean delete_event_handler(GtkWidget *widget, GdkEvent *event, gpointer user_data);

void print_and_quit(GtkButton *was_clicked, gpointer user_data)
{
    g_print("Gracias por usarme\n");
    gtk_main_quit();
    return;
}