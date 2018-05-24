#include "stack_help_gtk_window.h"
#include <gtk/gtk.h>

/*
 * Singnal is defined on lines 48-54,
 * and it's called on line 72 during window's 'destroy' event
 */

#define STACK_HELP_GTK_WINDOW_GLADE "../resources/window.glade" // You might need to change this, but maybe not.

/**  Structures  **/
struct _StackHelpGtkWindowClass
{
  GObjectClass __parent__;
};

struct _StackHelpGtkWindow
{
  GObject __parent__;
  
  GtkBuilder *builder;
};

/*  Signals  */
enum
{
  DESTROY_SIGNAL,
  LAST_SIGNAL,
};

static guint stack_help_gtk_window_signals [LAST_SIGNAL] = { 0, };

/**  Define type  **/
G_DEFINE_TYPE (StackHelpGtkWindow, stack_help_gtk_window, G_TYPE_OBJECT)

/**  Prototypes  **/
static void stack_help_gtk_window_finalize   (GObject *);
static void stack_help_gtk_window_on_destroy (GtkWindow *, gpointer);

/**  Methods  **/
static void
stack_help_gtk_window_class_init (StackHelpGtkWindowClass *klass)
{
  GObjectClass *gobject_class;
  gobject_class = G_OBJECT_CLASS (klass);
  gobject_class->finalize = stack_help_gtk_window_finalize;
  
  stack_help_gtk_window_signals[DESTROY_SIGNAL] =
    g_signal_new (g_intern_static_string ("destroy-signal"),
                  G_TYPE_FROM_CLASS (gobject_class),
                  G_SIGNAL_RUN_LAST,
                  0, NULL, NULL,
                  //G_STRUCT_OFFSET (StackHelpGtkWindowClass, destroy_signal),
                  //NULL, NULL,
                  g_cclosure_marshal_VOID__VOID,
                  G_TYPE_NONE, 0);
}

static void
stack_help_gtk_window_init (StackHelpGtkWindow *stack_help_gtk_window)
{
  GtkWidget *window;
  stack_help_gtk_window->builder = 
    gtk_builder_new_from_file(STACK_HELP_GTK_WINDOW_GLADE);
  window = (GtkWidget *) gtk_builder_get_object(stack_help_gtk_window->builder, "window");
  g_signal_connect(window, "destroy",
                   G_CALLBACK(stack_help_gtk_window_on_destroy),
                   stack_help_gtk_window);
}

static void
stack_help_gtk_window_on_destroy (GtkWindow *window, gpointer user_data)
{
  g_signal_emit(G_OBJECT(user_data), 
                stack_help_gtk_window_signals[DESTROY_SIGNAL], 0);
}

static void
stack_help_gtk_window_finalize (GObject *object)
{
  StackHelpGtkWindow *stack_help_gtk_window = STACK_HELP_GTK_WINDOW(object);
  g_clear_object(&(stack_help_gtk_window->builder));
}

/**  Public methods  **/

void
stack_help_gtk_window_show (StackHelpGtkWindow *stack_help_gtk_window)
{
  GObject *window;
  window = gtk_builder_get_object(stack_help_gtk_window->builder, "window");
  gtk_widget_show_all(GTK_WIDGET(window));
}

void
stack_help_gtk_window_close (StackHelpGtkWindow *stack_help_gtk_window)
{
  GObject *window;
  window = gtk_builder_get_object(stack_help_gtk_window->builder, "window");
  gtk_window_close(GTK_WINDOW(window));
}

StackHelpGtkWindow *
stack_help_gtk_window_new ()
{
  return g_object_new (TYPE_STACK_HELP_GTK_WINDOW, NULL);
}
