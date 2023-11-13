#include <unistd.h>

/**
 * my_putchar - to print
 * @c: a char
 * Return: the result
 */
int my_putchar (char c)
{
	return (write(1, &c, 1));
}
