#include "main.h"

/**
 *  * _printf - main function to print
 *   * @format: the character string
 *    * Return: the number of characters printed
 *     */
 
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;
		
	va_start(args, format);
		
	if (!format || !format[0])
		return (-1);
					
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				char c = va_arg(args, int);
				_putchar(c);
				count++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char *);
				print_string(str);
				count++;
			}
			else if (*format == '%')
			{
				_putchar('%');
				count++;
			}
			else if (*format == 'd' || *format == 'i')
			{
				int num = va_arg(args, int);
				if (num < 0)
					count ++;
				count += get_num_len(num);
				print_number(num);
			}
			else
			{
				_putchar('%');
				count++;
				if (*format)
				{
					_putchar(*format);
					count++;
				}
			}
			format++;
		}
		else
		{
			_putchar(*format);
			format++;
			count++;
		}
	}
	return (count);
}
