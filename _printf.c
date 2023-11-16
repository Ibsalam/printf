#include "main.h"

/**
 * print_buffer - Prints the contents of the buffer if it exists
 * @buffer: Array of chars
 @buff_index: Index at which to add the next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_index);

/**
 * _printf - Custom printf function
 * @format: Format string.
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_characters = 0;
	int flags, width, precision, size, buff_index = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_index++] = format[i];
			if (buff_index == BUFF_SIZE)
				print_buffer(buffer, &buff_index);
			printed_characters++;
		}
		else
		{
			print_buffer(buffer, &buff_index);
			flags = get_active_flags(format, &i);
			width = getwidth_specifier(format, &i, list);
			precision = calculatePrecision(format, &i, list);
			size = get_size_specifier(format, &i);
			++i;
			printed = handle_print_specifier(format, &i, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_characters += printed;
		}
	}

	print_buffer(buffer, &buff_index);

	va_end(list);

	return (printed_characters);
}

/**
 * print_buffer - Prints the contents of the buffer if it exists
 * @buffer: Array of chars
 * @buff_index: Index at which to add the next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_index)
{
	if (*buff_index > 0)
		write(1, &buffer[0], *buff_index);

	*buff_index = 0;
}
