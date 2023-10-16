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
	int count = 0;
	unsigned int formlen = strlen(format);
	unsigned int i = 0;
	char *chr;
	va_list args;

	va_start(args, format);
	while(formlen > i)
	{
		chr = format[i];
		if (next)
		{
			switch (chr)
			{
				case ('c'):
					write(1, va_arg(args, *char), 1);
					break;
				case ('s'):
					_printf(va_arg(args, *char));
					break;
			}
			count += 1;
		}
		if (chr != '%')
		{
			next = 0;
			write(1, chr, 1);
		} else
		{
			next = 1;
			continue;
		}
		count += 1;
		i++;

	}

	return (count);
}
