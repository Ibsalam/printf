#include "main.h"

/**
 * parser - print integer
 * @format: a constant
 * @funct_list: a member
 * @args: an int
 * Return: the result
 */
int parser(const char *format, conver_t funct_list[], va_list args)
{
	int i, j, r_val, printed_chars;

	printed_chars = 0;
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			for (j = 0; funct_list[j].sym != NULL; j++)
			{
				if (format[i + 1] == funct_list[j].sym[0])
				{
					r_val = funct_list[j].f(args);
					if (r_val == -1)
						return (-1);
					printed_chars += r_val;
					break;
				}
			}
			if (funct_list[j].sym == NULL && format[i + 1] != ' ')
			{
				if (format[i + 1] != '\0')
				{
					my_putchar(format[i]);
					my_putchar(format[i + 1]);
					printed_chars = printed_chars + 2;
				}
				else
					return (-1);
			}
			i = i + 1;
		}
		else
		{
			my_putchar(format[i]);
			printed_chars++;
		}
	}
	return (printed_chars);
}
