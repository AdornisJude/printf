#include "main.h"

/**
 * _string - handles printing of strings
 * @str: the string to print
 *
 * Return: the number of characters printed
 */
int _string(char *str)
{
	int i = 0;
	int len = 0;

	if (str == NULL)
	{
		_string("(null)");
		return (6);
	}
	while (str[i])
	{
		_putchar(str[i]);
		i++;
		len++;
	}
	return (len);
}
