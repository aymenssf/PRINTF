#include <stdarg.h>

int	addNumber(int n)
{
	int sum = 0;
	va_list ptr;
	va_start(ptr, n);
	for(int i = 0; i < n; i++)
		sum += va_arg()
}
