#include<unistd.h>

int main(void)
{
	char new = '\n';

	write(1, &new, 1);
}
