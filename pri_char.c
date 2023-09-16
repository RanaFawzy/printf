/**
 * print_string - Print a strings
 * @types: List of argument
 * @buffer: Buffer arrays to handle prints
 * @flags:  Calculate active flag
 * @width: widths
 * @precision: Precision specific
 * @size: Size specifiers
 * Return: Number of char print
 */
int print_string(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int length = 0, i;
char *str = va_arg(types, char *);
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
if (str == NULL)
{
str = "(null)";
if (precision >= 6)
str = "      ";
}
while (str[length] != '\0')
length++;
if (precision >= 0 && precision < length)
length = precision;
if (width > length)
{
if (flags & F_MINUS)
{
write(1, &str[0], length);
for (i = width - length; i > 0; i--)
write(1, " ", 1);
return (width);
}
else
{
for (i = width - length; i > 0; i--)
write(1, " ", 1);
write(1, &str[0], length);
return (width);
}
}
return (write(1, str, length));
}
/**
 * print_percent - Prints percent
 * @types: Lista of argument
 * @buffer: Buffer arrays to handle prints
 * @flags:  Calculate active flag
 * @width: widths.
 * @precision: Precisions specific
 * @size: Size specifies
 * Return: Number of char print
 */
int print_percent(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
UNUSED(types);
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
return (write(1, "%%", 1));
}
