#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<stdarg.h>

/**
 * _printf - description
 * @format: the character string and format
 * Description: the
 * Return: The number of character printed excluding the null byte
 */

int _printf(const char *format, ...)
{
	int next, r, count = 0;
	unsigned int i = 0, formlen = strlen(format);
	char chr, special;
	va_list args;

	va_start(args, format);
	while (formlen > i)
	{
		chr = format[i];
		if (next)
		{
			switch (chr)
			{
				case ('c'):
					write(1, va_arg(args, char *), 1);
					break;
				case ('s'):
					r = _printf(va_arg(args, char *));
					count += (r - 1);
					break;
				case ('%'):
					special = '%';
					write(1, &special, 1);
			}
			next = 0;
			count += 1;
			i++;
			continue;
		}
		i++;
		if (chr != '%')
			write(1, &chr, 1);
		if (chr == '%')
		{
			next = 1;
			continue;
		}
		count += 1;
	}
	return (count);
}
