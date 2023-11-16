#include "main.h"

/**
 * get_size_specifier - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments.
 * @index: Pointer to the current index in the format string.
 *
 * Return: The size to cast the argument.
 */
int get_size_specifier(const char *format, int *index)
{
	int current_index = *index + 1;
	int size = 0;

	if (format[current_index] == 'l')
	{
		size = S_LONG;
	}
	else if (format[current_index] == 'h')
	{
		size = S_SHORT;
	}

	if (size == 0)
	{
		*index = current_index - 1;
	}
	else
	{
		*index = current_index;
	}

	return (size);
}
