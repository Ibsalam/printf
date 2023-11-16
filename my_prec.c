#include "main.h"

/**
 * calculatePrecision - Calculates the precision for printing
 * @format: Formatted string specifying the format of the output
 * @currentIndex: Pointer to the current index in the format string
 * @argsList: List of arguments
 *
 * Return: The calculated precision.
 */
int calculatePrecision(const char *format, int *currentIndex, va_list argsList)
{
	int currentIdx = *currentIndex + 1;
	int precision = -1;

	if (format[currentIdx] != '.')
		return (precision);

	precision = 0;

	for (currentIdx += 1; format[currentIdx] != '\0'; currentIdx++)
	{
		if (isDigit(format[currentIdx]))
		{
			precision *= 10;
			precision += format[currentIdx] - '0';
		}
		else if (format[currentIdx] == '*')
		{
			currentIdx++;
			precision = va_arg(argsList, int);
			break;
		}
		else
			break;
	}

	*currentIndex = currentIdx - 1;

	return (precision);
}
