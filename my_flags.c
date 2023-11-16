#include "main.h"

/**
 * get_active_flags - Calculates active flags for printf-style formatting.
 * @format: Formatted string containing the format specifier.
 * @index: Pointer to the current position in the format string.
 *
 * Return: Integer representing the active flags (bitwise OR of flags).
 */
int get_active_flags(const char *format, int *index)
{
	int j, current_index;
	int active_flags = 0;
	const char FLAGS_CHARACTERS[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARRAY[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (current_index = *index + 1; format[current_index] != '\0'; current_index++)
	{
	for (j = 0; FLAGS_CHARACTERS[j] != '\0'; j++)
	{
		if (format[current_index] == FLAGS_CHARACTERS[j])
	{
		active_flags |= FLAGS_ARRAY[j];
		break;
	}
	}

	if (FLAGS_CHARACTERS[j] == 0)
	{
		break;
	}
	}

	*index = current_index - 1;

	return (active_flags);
}
