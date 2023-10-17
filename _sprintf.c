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
	int count = 0, formlen = strlen(format);
	char chr;

	while (formlen > count)
	{
		chr = format[count];
		write(1, &chr, 1);
		count++;
	}
	return (count);
}
