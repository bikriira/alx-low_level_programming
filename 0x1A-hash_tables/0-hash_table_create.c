#include "hash_tables.h"


/**
 * hash_table_create - Creates the hash table
 * @size: Size of the array
 *
 * Return: pointer to the newly created hash table or NULL if an error
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *table = malloc(sizeof(hash_table_t) * size);

	if (table == NULL)
		return (NULL);
	else
		return (table);
}
