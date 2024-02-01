#include "hash_tables.h"


/**
 * hash_table_get - Retrieves a value associated with a key
 * @ht: The hash table you want to look into
 * @key: The key you are looking for
 *
 * Return: The value associated with the element,
 *		   or NULL if key couldn’t be found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int elem_index;
	hash_node_t *current;

	elem_index = key_index((const unsigned char *)key, ht->size);

	if (ht == NULL || ht->array[elem_index] == NULL || strlen(key) == 0)
		return (NULL);
	if (strcmp(ht->array[elem_index]->key, key) == 0)
		return (ht->array[elem_index]->value);

	current = ht->array[elem_index];
	while (current != NULL)
	{
		if (strcmp(current->key, key) == 0)
			return (current->value);
		current = current->next;
	}
	return (NULL);
}
