#include "main.h"

int _printf(const char *format, ...);

/**
 * _printf - custom implementation of printf
 * @format: format specifier
 * @...: variable arguments
 *
 * Return: total length of characters printed or -1 on error
 */
int _printf(const char *format, ...)
{
	int len = 0;
	va_list func_arg;
	(void)format;

	if (format == NULL)
		return (-1);

	va_start(func_arg, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				char c = va_arg(func_arg, int);

				_putchar(c);
				len++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(func_arg, char *);

				if (str == NULL)
					str = "(null)";
				while (*str != '\0')
				{
					_putchar(*str);
					str++;
					len++;
				}
			}
			else if (*format == '%')
			{
				_putchar('%');
				len++;
			}
			else if (*format == 'd' || *format == 'i')
			{
				int num = va_arg(func_arg, int);

				len += _number(num);
			}
			else
			{
				_putchar('%');
				_putchar(*format);
				len += 2;
			}
		}
		else
		{
			_putchar(*format);
			len++;
		}
		format++;
	}
	va_end(func_arg);
	return (len);
}
