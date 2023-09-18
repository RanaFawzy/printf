#include "main.h"

/**
 * get_precision - Calculatess precision for printt
 * @format: Formatted strings which to prints the argumentt
 * @i: List of argumentt to print.
 * @list: list of arguments.
 *
 * Return: Precisions.
 */
int get_precision(const char *format, int *i, va_list list)
{
int precision = -1;
int curr_i = *i + 1;
if (format[curr_i] != '.')
return (precision);
precision = 0;
for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
{
if (is_digit(format[curr_i]))
{
precision *= 10;
precision += format[curr_i] - '0';
}
else if (format[curr_i] == '*')
{
curr_i++;
precision = va_arg(list, int);
break;
}
else
break;
}
*i = curr_i - 1;
return (precision);
}
