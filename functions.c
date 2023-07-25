#include "main.h"

/**
 *  * _putchar - writes the character c to stdout
 *   * @c: The character to print
 *    *
 *     * Return: On success 1.
 *      * On error, -1 is returned, and errno is set appropriately.
 *       */
int _putchar(char c)
{
		return (write(1, &c, 1));
}

/***/

int print_string(char *str)
{
	int i = 0;
		
	if (str == NULL)
	return (i);

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
	return (i);
}

/***/

void print_number(int num)
{
	if (num < 0)
	{
		_putchar('-');
		num *= (-1);
		print_number(num);
	}
	else if (num >= 10)
	{
		print_number(num / 10);
		print_number(num % 10);
	}
	else if (num < 10)
	{
		_putchar(num + '0');
	}
}

/***/

int get_num_len(int num)
{
	int len = 1;
	
	while (num > 9)
	{
		len++;
		num /= 10;
	}
	return len;
}
