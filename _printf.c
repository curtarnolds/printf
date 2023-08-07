#include "main.h"


/**
 * _printf - Mimics the standard library printf
 * @format: A format specifier
 * Return: The number of characters printed, excluding the null byte
 * at the end of the string
*/
int _printf(const char *format, ...)
{
	char *temp;
	int i = 0, count = 0;
	va_list arg_list;
	va_start(arg_list, format);

	while (format[i])
	{
		if (format[i] == '\\' && format[i + 1] != ' ')
		{
			switch (format[i + 1])
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
			i++;
			count++;
		}
		else if (format[i] == '%')
		{
			while (format[i + 1] == ' ')
				i++;
			switch (format[i + 1])
			{
				case 'c':
					_putchar(va_arg(arg_list, int));
					break;
				case 's':
					temp = va_arg(arg_list, char *);
					write(1, temp, strlen(temp));
					count = count + strlen(temp) - 1;
					break;
				case '%':
					_putchar('%');
					break;
				default:
					_putchar('%');
					_putchar(format[i + 1]);
					break;
			}
			i++;
			count++;
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
