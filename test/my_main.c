#include "main.h"
#include<stdio.h>
/**
 * main - the main function
 * Return: 0
 */

int main(void)
{
	int r;

	r = _printf("Hello World %% \t\r\f\n%s", "2Forget%s\n this is a %c \f");
	printf("\n%d\n", r);
	return (0);
}
