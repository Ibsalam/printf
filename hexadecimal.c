#include "main.h"

int print_hexadecimal(va_list args)
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
		check = check * 16;
	for (; check != 0;)
	{	
		len = len + my_putchar('0' + num / check);
		num = num % check;
		check = check / 16;
	}
	
		return (len);
}
int p_hexadecimal(va_list args)
{
	int n;

	n = print_hexadecimal(args);
	return (n);
}
