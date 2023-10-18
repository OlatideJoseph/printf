#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<stdarg.h>
#include "main.h"
/**
 * _printf - description
 * @format: the character string and format
 * Description: the
 * Return: The number of character printed excluding the null byte
 */

int _printf(const char *format, ...)
{
	unsigned int next, count = 0, i;
	char l, chr, special = '%';
	va_list args;

	if (format == NULL)
		return (_sprintf("(null)"));
	va_start(args, format);
	for (i = 0; strlen(format) > i; i++)
	{
		chr = format[i];
		if (next)
		{
			switch (chr)
			{
				case ('c'):
					l = va_arg(args, int);
					write(1, &l, 1);
					break;
				case ('s'):
					count += (_sprintf(va_arg(args, char *)) - 2);
					break;
				case ('%'):
					write(1, &special, 1);
					break;
			}
			next = 0;
			count += 1;
			continue;
		}
		if (chr && chr != '%')
			write(1, &chr, 1);
		if (chr == '%')
		{
			next = 1;
			continue;
		}
		count += 1;
	}
	va_end(args);
	return (count);
}
