#include "main.h"

/**
 * isPrintable - Checks if a character is printable
 * @c: The character to be evaluated.
 *
 * Return: 1 if c is printable, 0 otherwise.
 */
int isPrintable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * appendHexaCode - Appends ASCII in hexadecimal code to the buffer
 * @buffer: Array of characters.
 * @index: Index at which to start appending.
 * @asciiCode: ASCII code to be appended.
 *
 * Return: Always 3.
 */
int appendHexaCode(char asciiCode, char buffer[], int index)
{
	char hexMap[] = "0123456789ABCDEF";

	if (asciiCode < 0)
		asciiCode *= -1;

	buffer[index++] = '\\';
	buffer[index++] = 'x';

	buffer[index++] = hexMap[asciiCode / 16];
	buffer[index] = hexMap[asciiCode % 16];

	return (3);
}

/**
 * isDigit - Checks if a character is a digit
 * @c: The character to be evaluated.
 *
 * Return: 1 if c is a digit, 0 otherwise.
 */
int isDigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convertSizeNumber - Casts a number to the specified size
 * @num: Number to be cast.
 * @size: Type indicating the size to be casted.
 *
 * Return: Casted value of num.
 */
long int convertSizeNumber(long int num, int size)
{
	if (size == S_LONG)
		return num;
	else if (size == S_SHORT)
	return ((short)num);

	return ((int)num);
}

/**
 * convertSizeUnsigned - Casts an unsigned number to the specified size
 * @num: Unsigned number to be cast.
 * @size: Type indicating the size to be casted.
 *
 * Return: Casted value of num.
 */
long int convertSizeUnsigned(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
