#include "main.h"
#include<stdio.h>
/**
 * main - the main function
 * Return: 0
 */

int main(void)
{
	int r;

	r = _printf("Hello World %s %c", "Hello", 'A');
	printf("\n%d\n", r);
	return (0);
}
