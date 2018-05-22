#include "stack_help_gtk_window.h"
#include <gtk/gtk.h>
#include <stdio.h>

/*
 * Create window and close it after 3 seconds
 * "GLib-GObject-WARNING" should show up, something like
 * "signal id '158' is invalid for instance '0xXXXXXXXXXXXX'"
 */

void
on_destroy()
{
  printf("%s\n", "I should show up");
}

gboolean
quit_app()
{
  gtk_main_quit();
  return FALSE;
}

gboolean
time_passed(StackHelpGtkWindow *window)
{
  // Simulate 'X' button press
  stack_help_gtk_window_close(window);
  // Exit the program after next 3 seconds
  g_timeout_add_seconds(3, (GSourceFunc)quit_app, NULL);
  return FALSE;
}

int
main(int argc, char *argv[])
{
  StackHelpGtkWindow *window;
  gtk_init(&argc, &argv);
  window = stack_help_gtk_window_new();
  g_signal_connect(window, "destroy-signal", on_destroy, NULL);
  stack_help_gtk_window_show(window);
  g_timeout_add_seconds(3, (GSourceFunc)time_passed, window);
  gtk_main();
  g_clear_object(&(window));
  return 0;
}
