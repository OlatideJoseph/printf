#include "main.h"
#include<unistd.h>
#include <string.h>

/**
 * _sprintf - print all characters without any special effect
 * @format: pointer to the arguments
 * Return: the number of characters
 */

int _sprintf(const char *format)
{
	int i, count = 0, formlen = strlen(format);
	char chr;

	for (i = 0; formlen > i; i++)
	{
		chr = format[i];
		write(1, &chr, 1);
		if (chr != '%')
			count++;
		continue;
	}
	return (count);
}
