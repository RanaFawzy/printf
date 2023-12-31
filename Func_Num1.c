#include "main.h"
/**
 * print_hexa - Print hexadecimal num in lower or upper
 * @types: List of argument
 * @map_to: Arrays of values to maps the num
 * @buffer: Buffer arrays to handle prints
 * @flags: Calculate active flag
 * @flag_ch: Calculate active flag
 * @width:widths
 * @precision: Precision specific
 * @size: Size specifies
 * @size: Size specific
 * Return: Number of char print
 */
int print_hexa(va_list types, char map_to[], char buffer[],
int flags, char flag_ch, int width, int precision, int size)
{
int i = BUFF_SIZE - 2;
unsigned long int num = va_arg(types, unsigned long int);
unsigned long int init_num = num;
UNUSED(width);
num = convert_size_unsgnd(num, size);
if (num == 0)
buffer[i--] = '0';
buffer[BUFF_SIZE - 1] = '\0';
while (num > 0)
{
buffer[i--] = map_to[num % 16];
num /= 16;
}
if (flags & F_HASH && init_num != 0)
{
buffer[i--] = flag_ch;
buffer[i--] = '0';
}
i++;
return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
 * print_hexa_upper - Prints an unsigned number in upper
 * @types: List of argument
 * @buffer: Buffer arrays to handle prints
 * @flags:  Calculate active flag
 * @width: widths
 * @precision: Precision specific
 * @size: Size specifies
 * Return: Number of char print
 */
int print_hexa_upper(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
return (print_hexa(types, "0123456789ABCDEF", buffer,
flags, 'X', width, precision, size));
}

/**
 * print_octal - Print unsigned number in octal
 * @types: List of argument
 * @buffer: Buffer arrays to handle prints
 * @flags: Calculate active flag
 * @width: widths
 * @precision: Precis specific
 * @size: Size specifies
 * Return: Number of char print
 */
int print_octal(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int i = BUFF_SIZE - 2;
unsigned long int num = va_arg(types, unsigned long int);
unsigned long int init_num = num;
UNUSED(width);
num = convert_size_unsgnd(num, size);
if (num == 0)
buffer[i--] = '0';
buffer[BUFF_SIZE - 1] = '\0';
while (num > 0)
{
buffer[i--] = (num % 8) + '0';
num /= 8;
}
if (flags & F_HASH && init_num != 0)
buffer[i--] = '0';
i++;
return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
/**
 * print_unsigned - Print unsigned number
 * @types: List the argument
 * @buffer: Buffer arrays to handle prints
 * @flags:  Calculate active flag
 * @width: widths
 * @precision: Precision specific
 * @size: Size specifies
 * Return: Number of char print.
 */
int print_unsigned(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int i = BUFF_SIZE - 2;
unsigned long int num = va_arg(types, unsigned long int);
num = convert_size_unsgnd(num, size);
if (num == 0)
buffer[i--] = '0';
buffer[BUFF_SIZE - 1] = '\0';
while (num > 0)
{
buffer[i--] = (num % 10) + '0';
num /= 10;
}
i++;
return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
/**
 * print_hexadecimal - Print unsigned number in hexadecimal
 * @types: List of argument
 * @buffer: Buffer arrays to handle prints
 * @flags:  Calculate active flag
 * @width: width
 * @precision: Precision specific
 * @size: Size specifies
 * Return: Number of char print
 */
int print_hexadecimal(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
return (print_hexa(types, "0123456789abcdef", buffer,
flags, 'x', width, precision, size));
}
