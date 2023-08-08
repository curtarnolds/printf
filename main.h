#ifndef MAIN_H
#define MAIN_H

#define BUFFER 1024
#define true 1
#define false 0

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

int _printf(const char *format, ...);
int _putchar(char c);
void _handle_format_specifier(const char *format,
va_list *arg_list, int *count, int *i);
void _handle_escape_sequence(char format, int *count);
char *_int_to_string(long int num, unsigned long int base);
void _reverse(char str[], unsigned long int length);
void write_number(va_list *arg_list, int *count, unsigned long int base);
#endif
