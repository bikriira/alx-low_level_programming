#include "main.h"


/**
 * binary_to_uint - Converts a binary number to an unsigned int.
 * @b: Pointing to a string of 0 and 1 chars.
 *
 * Return: The converted number, or 0 if:
 *		   - There is one or more chars in the string b that is not 0 or 1.
 *		   - b is NULL.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int count = strlen(b) - 1, i = 0, sum = 0;

	if (b == NULL)
		return (0);
	while (b[i])
	{
		if (b[i] != '0' && b[i] != '1')
			return (0);
		sum += ((int)b[i] - 48) * power(2, count);
		i++;
		count--;
	}
	return (sum);
}


/**
 * power - Calculates the square of a number.
 * @base: The base.
 * @power: The power.
 *
 * Return: The base power @power.
 */
int power(int base, int power)
{
	int sum = 1, i;

	for (i = 0; i < power; i++)
	{
		sum *= base;
	}
	return (sum);
}
