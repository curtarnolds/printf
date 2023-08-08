#include "main.h"


/**
 * _reverse - Reverse a string
 * @str: The string to Reverse
 * @length: The length of the string
*/
void _reverse(char str[], unsigned long int length)
{
	unsigned long int start = 0;
	unsigned long int end = length - 1;
	char temp;

	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}


/**
 * _int_to_string - Convert integer to a string
 * @num: Integer to be converted
 * @base: The base of the integer
 * Return: The string representation of the integer, else NULL on failure
*/
char *_int_to_string(long int num, unsigned long int base)
{
	unsigned long int isNegative, i, charLength, rem, temp;
	char *str;

	isNegative = false;
	i = charLength = rem = 0;
	if (num == 0)
		charLength = 1;
	else if (num < 0 && base == 10)
	{
		isNegative = true;
		num = -num;
	}
	temp = num;
	while (temp != 0)
	{
		temp = temp / base;
		charLength++;
	}
	if (isNegative)
		charLength++;
	str = (char *) malloc((charLength + 2) * sizeof(char));
	if (str == NULL)
		exit(-1);
	if (num == 0)
		str[i++] = '0';
	else
	{
		while (num != 0)
		{
			rem = num % base;
			str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
			num = num / base;
		}
		if (isNegative)
			str[i++] = '-';
	}
	str[i] = '\0';
	_reverse(str, i);
	return (str);
}


/**
 * _nulled_write - Write to fd but represent NULL as (null)
 *
*/



/**
 * write_number - write a number to stdout
 * @arg_list: List of variable arguments
 * @count: Number of characters written
 * @base: The base of the number to write
*/
void write_number(va_list *arg_list, int *count, unsigned long int base)
{
	unsigned long int _int;
	char *temp;

	_int = va_arg(*arg_list, int);
	temp = _int_to_string(_int, base);
	_int = write(1, temp, strlen(temp));
	*count = *count + strlen(temp) - 1;
	free(temp);
}
