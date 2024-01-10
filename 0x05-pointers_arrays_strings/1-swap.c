#include "main.h"


/**
 * swap_int - A function that swaps the values of two integers
 * @a: Pointer to int a
 * @b: Pointer to int b
 *
 * Return: Void
 */
void swap_int(int *a, int *b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}
