#include "main.h"
#include <stdint.h>

/**
 * _printf - print integer
 * @format: a char
 * Return: the result
 */
int _printf(const char *format, ...)
{
	int printed_chars;
	conver_t funct_list[] = {
		{"c", p_char},
		{"s", p_string},
		{"%", p_percent},
		{"d", p_integer},
		{"i", p_integer},
		{"u", p_unsigned_integer},
		{"o", p_unsigned_oct},
		{"x", p_hexadecimal},
		{"X", p_hexadecimal},
		{NULL, NULL}
	};

	va_list args;

	if (format == NULL)
		return (-1);
	va_start(args, format);

	printed_chars = parser(format, funct_list, args);
	va_end(args);

	return (printed_chars);
}
