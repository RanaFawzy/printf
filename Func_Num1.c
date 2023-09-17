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
