#include "main.h"

/**
 * _bin - converts an unsinged interger to binary
 * @b: decimal to be converted
 * Return:  the number of characters printed
 */

int _bin(va_list b)
{
	unsigned int num = va_arg(b, unsigned int);
	int count = 0;
	unsigned int len = 0, powtwo = 1;
	unsigned int n = num;
	unsigned int j;

	if (n != 0)
	{
		num = n;
		len = 0;
		while (num != 0)
		{
			num = num / 2;
			len++;
		}
		powtwo = 1;
		for (j = 1; j <= len - 1; j++)
		{
			powtwo = powtwo * 2;
		}

		for (j = 1; j <= len; j++)
		{
			unsigned int digit = n / powtwo;

			_putchar(digit + '0');
			count++;
			n -= digit * powtwo;
			powtwo /= 2;
		}
	}
	else
	{
		_putchar('0');
		count++;
	}
	return (count);

}
