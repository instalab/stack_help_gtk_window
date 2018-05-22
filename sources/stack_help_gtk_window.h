#ifndef __STACK_HELP_GTK_WINDOW_H__
#define __STACK_HELP_GTK_WINDOW_H__

#include <glib-object.h>

G_BEGIN_DECLS

typedef struct _StackHelpGtkWindowClass  StackHelpGtkWindowClass;
typedef struct _StackHelpGtkWindow       StackHelpGtkWindow;

#define TYPE_STACK_HELP_GTK_WINDOW             (stack_help_gtk_window_get_type ())
#define STACK_HELP_GTK_WINDOW(obj)             (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_STACK_HELP_GTK_WINDOW, StackHelpGtkWindow))
#define STACK_HELP_GTK_WINDOW_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ((klass),  TYPE_STACK_HELP_GTK_WINDOW, StackHelpGtkWindowClass))
#define IS_STACK_HELP_GTK_WINDOW(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_STACK_HELP_GTK_WINDOW))
#define IS_STACK_HELP_GTK_WINDOW_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ((klass),  TYPE_STACK_HELP_GTK_WINDOW))
#define STACK_HELP_GTK_WINDOW_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS ((obj),  TYPE_STACK_HELP_GTK_WINDOW, StackHelpGtkWindowClass))

StackHelpGtkWindow *stack_help_gtk_window_new ();
void stack_help_gtk_window_show  (StackHelpGtkWindow *stack_help_gtk_window);
void stack_help_gtk_window_close (StackHelpGtkWindow *stack_help_gtk_window);

G_END_DECLS

#endif
