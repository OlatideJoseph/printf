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
	int next, r, count = 0, i, formlen = strlen(format);
	char l, chr, special = '%';
	va_list args;

	va_start(args, format);
	for (i = 0; formlen > i; i++)
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
					r = _sprintf(va_arg(args, char *));
					count += (r - 1);
					break;
				case ('%'):
					write(1, &special, 1);
					break;
			}
			next = 0;
			count += 1;
			continue;
		}
		if (chr != '%')
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
