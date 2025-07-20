#include "main.h"

static int handle_specifier(const char *format, int *i,
			    va_list args, spec_t funcs[]);

/**
 * _printf - A custom implementation printf function.
 * @format: The format string.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	int i = 0, count = 0;
	int printed_chars;
	va_list args;
	spec_t funcs[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{NULL, NULL}
	};

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			printed_chars = handle_specifier(format, &i, args, funcs);
			if (printed_chars == -1)
			{
				va_end(args);
				return (-1);
			}
			count += printed_chars;
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}

/**
 * handle_specifier - Handles the format specifier logic for _printf.
 * @format: The format string.
 * @i: Pointer to the current index in the format string.
 * @args: The va_list of arguments.
 * @funcs: The array of specifier-function mappings.
 *
 * Return: The number of characters printed by the handler.
 */
static int handle_specifier(const char *format, int *i,
			    va_list args, spec_t funcs[])
{
	int j = 0, count = 0;

	(*i)++;

	if (format[*i] == '\0')
		return (-1);

	while (funcs[j].spec != NULL)
	{
		if (*(funcs[j].spec) == format[*i])
		{
			count += funcs[j].f(args);
			return (count);
		}
		j++;
	}

	_putchar('%');
	_putchar(format[*i]);
	return (2);
}

/**
 * print_char - Prints a character.
 * @args: A list of arguments pointing to the character to be printed.
 *
 * Return: 1 (for one character printed).
 */
int print_char(va_list args)
{
	_putchar(va_arg(args, int));
	return (1);
}

/**
 * print_string - Prints a string.
 * @args: A list of arguments pointing to the string to be printed.
 *
 * Return: The number of characters printed.
 */
int print_string(va_list args)
{
	int i;
	char *str = va_arg(args, char *);

	if (str == NULL)
		str = "(null)";

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}

	return (i);
}

/**
 * print_percent - Prints a percent symbol.
 * @args: A list of arguments (unused).
 *
 * Return: 1 (for one character printed).
 */
int print_percent(__attribute__((unused))va_list args)
{
	_putchar('%');
	return (1);
}

