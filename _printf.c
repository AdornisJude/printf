#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/**
* _printf - prints to stdout
* @format: format specifier
* Return: total count of characters printed
*/

// Custom putchar function to write a character to standard output
int custom_putchar(char c)
{
    return (write(1, &c, 1));
}

// Custom function to handle printing strings
int custom_string(char *str)
{
    int i = 0;
    int count = 0;
    if (str == NULL)
    {
        custom_string("(null)");
        return (i);
    }
    while (str[i])
    {
        custom_putchar(str[i]);
        i++;
    }
    return (i);
}

// Custom printf implementation
int custom_printf(const char *format, ...)
{
    int count = 0;

    va_list func_arg;
    va_start(func_arg, format);

    if (format != NULL || !format[0])
        return (-1);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == 'c')
            {
                char c = va_arg(func_arg, int);
                count = count + custom_putchar(c);
            }
            else if (*format == 's')
            {
                char *str = va_arg(func_arg, char *);
                count = custom_string(str);
            }
            else if (*format == '%')
            {
                custom_putchar('%');
                count++;
            }
            else
            {
                custom_putchar(*format);
                count++;
            }
        }
        format++;
    }
    va_end(func_arg);
    return (count);
}
