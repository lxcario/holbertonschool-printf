#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * struct specifier - Struct to map a specifier to a function
 *
 * @spec: The conversion specifier character
 * @f: The function associated with the specifier
 */
typedef struct specifier
{
	char *spec;
	int (*f)(va_list);
} spec_t;

int _putchar(char c);
int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);

#endif
