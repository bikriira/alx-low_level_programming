#include "main.h"


/**
 * get_bit - Finds value of a bit at a given index.
 * @n: The number to be worked on.
 * @index: The name explain it self😂
 *
 * Return: The value of a bit at a given index.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
		return (-1);
	return ((int)((n >> index) & 1));
}
