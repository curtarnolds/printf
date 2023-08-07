#ifndef MAIN_H
#define MAIN_H

#define BUFFER 1024

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

int _printf(const char *format, ...);
int _putchar(char c);
void _handle_format_specifier(const char *format,
va_list *arg_list, int *count, int *i);
void _handle_escape_sequence(char format, int *count);
#endif
