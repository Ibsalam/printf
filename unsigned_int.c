#include "main.h"

int print_un_number(va_list args)
{
	int n;
	int check;
	int len;
	unsigned int num;

	n = va_arg(args, int);
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
int p_unsigned_integer(va_list args)
{
	int n;

	n = print_un_number(args);
	return (n);
}
