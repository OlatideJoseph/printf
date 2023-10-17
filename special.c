#include<stdio.h>
#include<unistd.h>
#include<stdarg.h>
#include "main.h"
/**
 * special -  to handle all the printing for special formats
 * @chr: the character entered
 *
 * Return: none
 */

int special(char chr, ...)
{
	int r, l;
	char s = '%';
	va_list args;

	va_start(args, chr);
	switch (chr)
	{
		case ('c'):
			l = va_arg(args, int);
			write(1, &l, 1);
			break;
		case ('s'):
			r = _sprintf(va_arg(args, char *));
			return (r - 1);
		case ('%'):
			write(1, &s, 1);
			break;
	}
	return (1);
}
