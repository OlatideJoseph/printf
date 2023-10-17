#include<unistd.h>
#include<stdio.h>
#include<stdarg.h>

/**
 * newline - print a newline
 * Return:void
 */

void newline(void)
{
	int new = '\n';

	write(1, &new, 1);
}

void _sprint(const char *str);

/**
 * _printf - description
 * @format: the character string and format
 * Description: the
 * Return: The number of character printed excluding the null byte
 */

int _printf(const char *format, ...)
{
	int next, r, count = 0, i = 0;
	char l, chr, special = '%';
	va_list args;

	va_start(args, format);
	while (*format != '\0')
	{
		chr = *format;
		if (next)
		{
			switch (chr)
			{
				case ('c'):
					l = va_arg(args, int);
					write(1, &l, 1);
					break;
				case ('s'):
					r = _printf(va_arg(args, char *));
					count += (r - 1);
					break;
				case ('%'):
					write(1, &special, 1);
					break;
			}
			*format++;
			next = 0;
			count += 1;
			continue;
		}
		if (chr != '%')
			write(1, &chr, 1);
		if (chr == '%')
		{
			next = 1;
			*format++;
			continue;
		}
		*format++;
		count += 1;
	}
	return (count);
}
