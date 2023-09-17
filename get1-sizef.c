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
