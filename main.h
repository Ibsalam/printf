#ifndef MY_PRINTF
#define MY_PRINTF
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h>

struct convert
{
	char *sym;
	int (*f)(va_list);
};
typedef struct convert conver_t;

int my_putchar (char c);
int _printf(const char *format, ...);
void _vprint(const char *format, va_list args);
int parser (const char *format, conver_t funct_list[], va_list args);
int p_unsigned_integer(va_list args);
int print_un_number(va_list args);
int print_un_oct(va_list args);
int p_unsigned_oct(va_list args);
int print_hexadecimal(va_list args);
int p_hexadecimal(va_list args);
int p_char (va_list);
int p_string (va_list args);
int p_percent (va_list);
int print_unsigned_number (unsigned int n);
int print_number (va_list);
int p_integer (va_list);

#endif

