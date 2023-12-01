#include "main.h"


/**
 *
 *
 *
 *
 *
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if ((*n >> index)| 1)
		return (1);
	return (-1);
}
