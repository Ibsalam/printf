#include "main.h"

/**
 * print_binary - Converts an unsigned int to binary and prints it.
 * @args: A va_list containing the unsigned int to be converted.
 *
 * Return: The number of characters printed.
 */
int print_binary(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	int count = 0;

	int i;
	for (i = 31; i >= 0; i--)
{
	putchar((num & (1u << i)) ? '1' : '0');
	count++;
}

	return (count);
}
