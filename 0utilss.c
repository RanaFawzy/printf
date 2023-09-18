#include "main.h"

/**
 * is_printable - Evaluates if a char is a printableee….
 * @c: Char to be evaluateddd….
 * Return: 1 if c is printable, 0 otherwise
 */
int is_printable(char c)
{
if (c >= 32 && c < 127)
return (1);
return (0);
}
/**
 * convert_size_number - Casts the number to the specified size,,,
 * @num: Number to be casteddd…..
 * @size: Number indicating the type to be casteddd….
 * Return: Casted value of num,,,,
 */
long int convert_size_number(long int num, int size)
{
if (size == S_LONG)
return (num);
else if (size == S_SHORT)
return ((short)num);
return ((int)num);
}
