#ifndef MAIN_H_
#define MAIN_H_

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 * @fmt: The format specifier character.
 * @fn: The function associated with the format specifier.
 */
struct fmt
{
    char fmt;
    int (*fn)(va_list, char[], int, int, int, int);
};

typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_print_specifier(const char *fmt, int *i,
                           va_list list, char buffer[], int flags, int width, int precision, int size);

int specifier_char(va_list args, char buffer[],
        int flags, int width, int precision, int size);
int specifier_string(va_list args, char buffer[],
        int flags, int width, int precision, int size);
int specifier_percent(va_list args, char buffer[],
        int flags, int width, int precision, int size);
int specifier_integer(va_list args, char buffer[],
        int flags, int width, int precision, int size);
int specifier_binary(va_list args, char buffer[],
        int flags, int width, int precision, int size);
int specifier_unsigned(va_list args, char buffer[],
                        int flags, int width, int precision, int size);
int specifier_octal(va_list args, char buffer[],
                        int flags, int width, int precision, int size);
int specifier_hexadecimal(va_list args, char buffer[],
                                int flags, int width, int precision, int size);
int specifier_hexa_upper(va_list args, char buffer[],
                                int flags, int width, int precision, int size);
int specifier_hexa(va_list args, char map_to[], char buffer[],
                        int flags, char flag_ch, int width, int precision, int size);
int specifier_non_printable(va_list args, char buffer[],
                int flags, int width, int precision, int size);
int specifier_pointer(va_list args, char buffer[],
                        int flags, int width, int precision, int size);
int get_active_flags(const char *format, int *index);
int getwidth_specifier(const char *format, int *index, va_list list);
int calculatePrecision(const char *format, int *currentIndex, va_list argsList);
int get_size_specifier(const char *format, int *index);
int specifier_reverse(va_list args, char buffer[],
                        int flags, int width, int precision, int size);
int specifier_rot13string(va_list args, char buffer[],
                        int flags, int width, int precision, int size);
int print_number(int is_negative, int index, char buffer[],
                int flags, int width, int precision, int size);
int print_pointer(char buffer[], int index, int length,
                int width, int flags, char padding, char extra_char, int padding_start);
int print_unsigned(int is_negative, int index,
                        char buffer[], int flags, int width, int precision, int size);
int print_num(int index, char buffer[],
                int flags, int width, int precision,
                int length, char padding, char extra_char)

int isPrintable(char c);
int appendHexaCode(char asciiCode, char buffer[], int index);
int isDigit(char c);

long int convertSizeNumber(long int num, int size);
long int convertSizeUnsigned(unsigned long int num, int size);

#endif /* MAIN_H */
