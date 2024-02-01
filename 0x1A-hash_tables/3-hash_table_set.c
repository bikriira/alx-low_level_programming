#include "hash_tables.h"


/**
 * hash_table_set - A function that adds an element to the hash table
 * @ht: The hash table
 * @key: The key of the element
 * @value: The value of the element
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int element_index;
	hash_node_t *element = malloc(sizeof(hash_node_t));

	if (element == NULL || strlen(key) == 0 || Key == NULL || ht == NULL)
		return (0);

	element->key = strdup(key);
	element->value = strdup(value);
	element->next = NULL;
	element_index = key_index((const unsigned char *)key, ht->size);

	if (ht->array[element_index] == NULL)
	{
		ht->array[element_index] = element;
	}
	else
	{
		element->next = ht->array[element_index];
		ht->array[element_index] = element;
	}

	return (1);
}
