#include "main.h"

/**
 * handle_print_specifier - Prints an argument based on its type
 * @fmt: Formatted string in which to print the arguments.
 * @index: Pointer to the current index in the format string.
 * @list: List of arguments to be printed.
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags.
 * @width: Width specifier.
 * @precision: Precision specifier.
 * @size: Size specifier.
 * Return: (Number of characters printed) on success, -1 on error.
 */
int handle_print_specifier(const char *fmt, int *index, va_list list,
			char buffer[], int flags, int width, int precision, int size)
{
	int unknown_length = 0;
	int printed_characters = -1;

	specifier_t specifiers[] = {
		{'c', specifier_char}, {'s', specifier_string}, {'%', specifier_percent},
		{'i', specifier_int}, {'d', specifier_int}, {'b', specifier_binary},
		{'u', specifier_unsigned}, {'o', specifier_octal}, {'x', specifier_hexadecimal},
		{'X', specifier_hexa_upper}, {'p', specifier_pointer}, {'S', specifier_non_printable},
		{'r', specifier_reverse}, {'R', specifier_rot13string}, {'\0', NULL}
	};

	for (int i = 0; specifiers[i].specifier != '\0'; i++)
	{
		if (fmt[*index] == specifiers[i].specifier)
		{
		return (specifiers[i].function(list, buffer, flags, width, precision, size));
		}
	}

	if (specifiers[i].specifier == '\0')
	{
		if (fmt[*index] == '\0')
		{
			return (-1);
		}

		unknown_length += write(1, "%%", 1);

		if (fmt[*index - 1] == ' ')
		{
			unknown_length += write(1, " ", 1);
		}
		else if (width)
		{
			--(*index);
			while (fmt[*index] != ' ' && fmt[*index] != '%')
			{
				--(*index);
			}

			if (fmt[*index] == ' ')
			{
				--(*index);
			}

			return (1);
		}

		unknown_length += write(1, &fmt[*index], 1);

		return (unknown_length);
	}

	return (printed_characters);
}
