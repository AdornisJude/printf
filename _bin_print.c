#include <stdarg.h>
#include "main.h"

/**
 * print_binary - Convert an unsigned integer to binary and print it.
 * @num: The number to be converted.
 *
 * Return: The number of characters printed.
 */
int print_binary(unsigned int num)
{
	int count = 0;
	unsigned int len = 0, powtwo = 1, n = num;
	unsigned int j;

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	while (n != 0)
	{
		n = n / 2;
		len++;
	}

	for (j = 1; j <= len - 1; j++)
	{
		powtwo = powtwo * 2;
	}

	for (j = 1; j <= len; j++)
	{
		unsigned int digit = num / powtwo;

		_putchar(digit + '0');
		count++;
		num -= digit * powtwo;
		powtwo /= 2;
	}

	return (count);
}

/**
 * print_bin - Wrapper function for print_binary.
 * @b: The number in decimal to be converted.
 *
 * Return: The number of characters printed.
 */
int print_bin(va_list b)
{
	return (print_binary(va_arg(b, unsigned int)));
}
