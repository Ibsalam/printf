#include "main.h"
#include <limits.h>

/**
 * print_binary - Prints the binary representation of an unsigned int.
 * @val: A va_list containing the unsigned int to be converted.
 *
 * Return: The number of characters printed.
 */
int print_binary(va_list val __attribute__((unused)))
{
	int has_set_bit = 0;
	int count = 0;
	unsigned int num = va_arg(val, unsigned int);
	unsigned int bit_mask;

	for (int i = CHAR_BIT * sizeof(unsigned int) - 1; i >= 0; i--)
	{
		bit_mask = 1u << i;
		if (num & bit_mask)
		{
			has_set_bit = 1;
			_putchar('1');
		}
		else if (has_set_bit || i == 0)
		{
			_putchar('0');
		}
		count++;
	}

	return (count);
}
