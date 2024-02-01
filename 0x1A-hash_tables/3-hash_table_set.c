#include "hash_tables.h"


int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *element = malloc(sizeof(hash_node_t));
	unsigned long int element_index;

	if (element == NULL || strlen(key) == 0)
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
