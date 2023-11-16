#include "main.h"

/**
 * getwidth_specifier - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @index: Pointer to the current index in the format string.
 * @list: List of arguments to be printed.
 *
 * Return: The calculated width.
 */
int getwidth_specifier(const char *format, int *index, va_list list)
{
	int current_index;
	int width = 0;

	for (current_index = *index + 1; format[current_index] != '\0'; current_index++)
	{
		if (is_digit(format[current_index]))
		{
			width *= 10;
			width += format[current_index] - '0';
		}
		else if (format[current_index] == '*')
		{
			current_index++;
			width = va_arg(list, int);
		break;
		}
		else
		{
			break;
		}
	}

	*index = current_index - 1;

	return (width);
}
