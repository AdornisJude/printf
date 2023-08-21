#include "main.h"

/**
 * _number - handles printing of numbers
 * @num: the number to print
 *
 * Return: the number of characters printed
 */
int _number(int num)
{
	int len = 0;

	if (num < 0)
	{
		_putchar('-');
		len++;
		num = -num;
	}
	if (num >= 10)
	{
		len += _number(num / 10);
		len += _number(num % 10);
	}
	else if (num < 10)
	{
		_putchar(num + '0');
		len++;
	}
	return (len);
}
