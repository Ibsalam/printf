#include "main.h"

/**
 * p_string - print string
 * @args: an int
 * Return: the result
 */
int p_string(va_list args)
{
	int i;
	const char *s;

	s = va_arg(args, const char *);

	if (s == NULL)
		s = "(null)";

	for (i = 0; s[i] != '\0'; i++)
		my_putchar(s[i]);
	return (i);
}

/**
 * p_percent - print percent
 * @args: an int
 * Return: the result
 */
int p_percent(__attribute__((unused)) va_list args)
{
	my_putchar('%');
	return (1);
}

/**
 * p_integer - print integer
 * @args: an int
 * Return: the result
 */
int p_integer(va_list args)
{
	int n;

	n = print_number(args);
	return (n);
}
