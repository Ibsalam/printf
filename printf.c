#include "main.h"
#include <stdint.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

/**
 * _printf - print integer
 * @format: a char
 * Return: the result
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	int buffer_index = 0;
	const char *str;
	char buffer[BUFFER_SIZE];

	va_start(args, format);

	while (*format)
{
	if (*format == '%')
{
		format++;
		switch (*format)
{
		case 'c':
		buffer[buffer_index++] = (char) va_arg(args, int);
			count++;
			break;

		case 's':
		str = va_arg(args, const char *);
		while (*str)
{
		buffer[buffer_index++] = *str++;
			count++;
		if (buffer_index == BUFFER_SIZE - 1)
{
		buffer[buffer_index] = '\0';
		write(1, buffer, buffer_index);
		buffer_index = 0;
}
}
			break;

		case '%':
		buffer[buffer_index++] = '%';
			count++;
			break;

		default:
		buffer[buffer_index++] = '%';
			count++;
			break;
}
}else{
		buffer[buffer_index++] = *format;
		count++;
}

		if (buffer_index == BUFFER_SIZE - 1)
{
		buffer[buffer_index] = '\0';
		write(1, buffer, buffer_index);
		buffer_index = 0;
}

		format++;
}

	buffer[buffer_index] = '\0';
	write(1, buffer, buffer_index);

	va_end(args);

	return (count);
}
