#include "main.h"

/**
 * print_number - print integer
 * @args: an int
 * Return: the result
 */
int print_number(va_list args)
{
	int n;
	int check;
	int len;
	unsigned int num;

	n = va_arg(args, int);
	check = 1;
	len = 0;

	if (n < 0)
	{
		len += my_putchar('-');
		num = n * -1;
	}
	else
		num = n;
	for (; num / check > 9;)
		check *= 10;
	for (; check != 0;)
	{
		len += my_putchar('0' + num / check);
		num %= check;
		check /= 10;
	}
	return (len);
}

/**
 * print_unsigned_number - print integer
 * @n: an int
 * Return: the result
 */
int print_unsigned_number(unsigned int n)
{
	int check;
	int len;
	unsigned int num;

	check = 1;
	len = 0;
	num = n;

	for (; num / check > 9;)
		check *= 10;
	for (; check != 0;)
	{
		len += my_putchar('0' + num / check);
		num %= check;
		check /= 10;
	}
	return (len);
}

/**
 * p_char - print integer
 * @args: an int
 * Return: the result
 */
int p_char(va_list args)
{
	char value;

	value = va_arg(args, int);

	my_putchar(value);
	return (1);
}
