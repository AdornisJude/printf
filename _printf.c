#include "main.h"

/**
 * _printf - custom implementation of printf
 * @format: format specifier
 * @...: variable arguments
 *
 * Return: total count of characters printed
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list func_arg;

	va_start(func_arg, format);

	if (format == NULL || !format[0])
		return (-1);

	while (*format != '\0')
	{
		if (*format == '%')
		{	
			format++;

			if (*format == 'c')
			{
				char c = va_arg(func_arg, int);
				_putchar(c);
				count++;
			}
			else if (*format =='s')
			{
				char(*str) = va_arg(func_arg, char *);

				while (*str != '\0')
				{
					_putchar(*str);
					str++;
					count++;
				}	
			}
		}
		else if (*format == '%')
		{
			_putchar('%');
			count++;
		}
		else
		{
			_putchar(*format);
			count++;
		}
		format++;
	}
	va_end(func_arg);
	return (count);
}
