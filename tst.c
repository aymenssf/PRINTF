#include <stdarg.h>
#include <stdio.h>
int main()
{
	int a = 3;
	char *str = "12";
	str[a - 4] = 'c';
	printf("%c",str[a - 4]);
}
