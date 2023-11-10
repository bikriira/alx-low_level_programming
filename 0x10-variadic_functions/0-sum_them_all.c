#include <stdarg.h>
#include "variadic_functions.h"

/**
  * sum_them_all - adds all its parameters
  * @n : Holdsd the number of passed arguments
  * Return : sum 
  */

int sum_them_all(const unsigned int n, ...)
{
	va_list arg;
	int sum = 0;
	unsigned int i;

	va_start(arg, n);
	if (n == 0)
	{
		return(0);
	}
	for (i = 0; i < n; i++)
	{
		int param = va_arg(arg, int);
		sum += param;
	}
	va_end(arg);

	return (sum);
}

