#include "main.h"


/**
 * _printf - Mimics the standard library printf
 * @format: A format specifier
 * Return: The number of characters printed, excluding the null byte
 * at the end of the string
*/
int _printf(const char *format, ...)
{
	va_list arg_list;
	int i = 0, count = 0;

	if (format == NULL)
		return (-1);
	va_start(arg_list, format);
	while (format[i])
	{
		if (format[i] == '\\' && format[i + 1] != ' ')
		{
			_handle_escape_sequence(format[i + 1], &count);
			i++;
		}
		else if (format[i] == '%')
		{
			if (!format[i + 1])
			{
				;
				count--;
				break;
			}
			while (format[i + 1] == ' ')
				i++;
			_handle_format_specifier(format, &arg_list, &count, &i);
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
		i++;
	}
	va_end(arg_list);
	return (count);
}


/**
 * _handle_escape_sequence - ...
 * @format: ...
 * @count: ...
*/
void _handle_escape_sequence(char format, int *count)
{
	switch (format)
	{
		case 'n':
			_putchar('\n');
			break;
		case 't':
			_putchar('\t');
			break;
		default:
			_putchar('\\');
			break;
	}
	(*count)++;
}


/**
 * _handle_format_specifier - ...
 * @format: ...
 * @arg_list: ...
 * @count: ...
 * @i: ...
*/
void _handle_format_specifier(const char *format, va_list *arg_list,
int *count, int *i)
{
	char *temp;

	switch (format[*i + 1])
	{
		case 'c':
			_putchar(va_arg(*arg_list, int));
			break;
		case 's':
			temp = va_arg(*arg_list, char *);
			if (temp == ((char *)0))
			{
				write(1, "(null)", strlen("(null)"));
				(*count) = *count + strlen("(null)") - 1;
			}
			else
			{
				write(1, temp, strlen(temp));
				*count = *count + strlen(temp) - 1;
			}
			break;
		case '%':
			_putchar('%');
			break;
		case 'b':
			write_number(arg_list, count, 2);
			break;
		case 'd':
		case 'i':
			write_number(arg_list, count, 10);
			break;
		default:
			_putchar('%');
			_putchar(format[*i + 1]);
			(*count)++;
			break;
	}
	(*i)++;
	(*count)++;
}
