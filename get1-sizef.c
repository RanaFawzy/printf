#include "main.h"

/**
 * get_size - Calculates the size to cast a argumenttt.
 * @format: Formatted string in which to print a argumentsss.
 * @i: List of arguments to be printed…
 *
 * Return: Precisionn…
 */
int get_size(const char *format, int *i)
{
int curr_i = *i + 1;
int size = 0;
if (format[curr_i] == 'l')
size = S_LONG;
else if (format[curr_i] == 'h')
size = S_SHORT;
if (size == 0)
*i = curr_i - 1;
else
*i = curr_i;
return (size);
}
/**
 * print_hexadecimal - Printss an unsigned number in hexadecimal notation,.
 * @types: Listaa of argumentsss,.,.
 * @buffer: Buffer array to handle printtt
 * @flags:  Calculates active flagsss,.,.,.
 * @width: get width,,,
 * @precision: Precision specificationn,,,
 * @size: Size specifierrr......
 * Return: Number of char was printed,,,,
 */
int print_hexadecimal(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
return (print_hexa(types, "0123456789abcdef", buffer,
flags, 'x', width, precision, size));
}
/**
 * print_hexa - Printss a hexadecimal number in lower or upperr,.,.
 * @types: Lista of argumentsss,.,.
 * @map_to: Array of values to map a number to to .,.,
 * @buffer: Bufferr array to handle printtt,.,.
 * @flags:  Calculatess active flagsss,.,.
 * @flag_ch: Calculatess active flagsss,.,.
 * @width: get width,.,.
 * @precision: Precision specificationnn,.,.,.,.
 * @size: Size specifierrr......
 * @size: Size specificationnn,,,,,
 * Return: Number of char was printed,,,,,,,
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
