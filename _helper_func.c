#include "main.h"


/**
 * _reverse - Reverse a string
 * @str: The string to Reverse
 * @length: The length of the string
*/
void _reverse(char str[], int length)
{
	int start = 0;
	int end = length - 1;
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
char *_int_to_string(int num, int base)
{
	int isNegative, i, charLength, rem, temp;
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
	str = (char *) malloc((charLength + 1) * sizeof(char));
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
