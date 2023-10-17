#include "main.h"
#include<stdio.h>
/**
 * main - the main function
 * Return: 0
 */

int main(void)
{
	int r;

	r = _printf("Hello World %% \t\r\f\n%s", "2Forget");
	printf("\n%d\n", r);
	r = _sprintf("special characters %s %d");
	printf("\n%d\n", r);
	return (0);
}
