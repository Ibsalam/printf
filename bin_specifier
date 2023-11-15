#include "main.h"

/**
 * print_binary - Converts an unsigned int to binary and prints it.
 * @val: A va_list containing the unsigned int to be converted.
 *
 * Return: The number of characters printed.
 */
int print_binary(va_list val)
{
	int flag = 0;
	int cont = 0;
	int i, a = 1, b;
	unsigned int num = va_arg(val, unsigned int);
	unsigned int p;

	for (i = 0; i < 32; i++)
	{
		p = ((a << (31 - i)) & num);
		if (p >> (31 - i))
			flag = 1;
		if (flag)
		{
			b = p >> (31 - i);
			my_putchar(b + '0');
			cont++;
		}
	}
	if (cont == 0)
	{
		cont++;
		my_putchar('0');
	}
	return (cont);
}
