#include<stdio.h>
#include<stdarg.h>
#include "variadic_functions.h"

/**
 * print_numbers : prints numbers, followed by a new line
 * @separator: comma space
 * @n: elements to be printed
 * Return: void
 */

void print_numbers(const char *separator, const unsigned int n, ...)
{
	unsigned int i;

	va_list arg;
	va_start(arg, n);
	for (i = 0; i < n; i++)
	{
		if (separator == NULL || *separator == 0)
			separator = "";
		else
			sep = (char *) separator;
		if ( ! (n == i + 1))
			printf("%d%s", va_arg(arg, int), separator);
		else
			printf("%d", va_arg(arg, int));
	}
	printf("\n");
	va_end(arg);	
}