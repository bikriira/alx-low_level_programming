#include "hash_tables.h"


/**
 * key_index - Uses the hash_djb2 to gives the index of a key.
 * @key: The string to be parsed
 * @size: The size of the table we created
 *		  (helps toensure that the key is in range)
 *
 * Return: The calculated index
 **/
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int index = hash_djb2(key);

	if (index >= size)
		index = index % size;

	return (index);
}
