#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<stdarg.h>
/*
 * _printf - handling format
 * @*format: the character string and format
 * Return: The number of character printed excluding the null byte
 */

int _printf(const char *format, ...)
{
	int next;
	int r;
	int count = 0;
	unsigned int formlen = strlen(format);
	unsigned int i = 0;
	char chr;
	char special;
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
					next = 0;
					break;
				case ('s'):
					r = _printf(va_arg(args, char *));
					count += r;
					next = 0;
					continue;
				case ('%'):
					special = '%';
					write(1, &special, 1);
					next = 0;
					break;
			}
			count += 1;
			i++;
			continue;
		}
		if (chr != '%')
		{
			next = 0;
			write(1, &chr, 1);
		} else
		{
			next = 1;
			i++;
			continue;
		}
		count += 1;
		i++;

	}

	return (count);
}
