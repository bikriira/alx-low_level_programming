#include "main.h"

/**
 * get_endianness - Function that checks the endianness.
 *
 * Return: 0 if big-endian, 1 if little-endian
 */
int get_endianness(void)
{
	char *ch;
	unsigned int x;

	x = 1;
	ch = (char *) &x;

	return ((int)*ch);
}
