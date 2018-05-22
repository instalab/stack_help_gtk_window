cmake_minimum_required(VERSION 3.9.6)
include(FindPkgConfig)
project(StackHelp)

pkg_search_module(GTK REQUIRED gtk+-3.0)

include_directories(${GTK_INCLUDE_DIRS})
add_definitions(${GTK_CFLAGS_OTHER})
add_executable(StackHelp sources/main.c sources/stack_help_gtk_window.c)
target_link_libraries(StackHelp ${GTK_LIBRARIES})
