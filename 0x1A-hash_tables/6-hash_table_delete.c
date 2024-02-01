#include "hash_tables.h"


/**
 * hash_table_delete - i.e frees the table correctly
 * @ht: The hash table
 *
 * Return: Void
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *current, *next;

	if (ht == NULL)
		return;

	for  (i = 0; i < ht->size; i++)
	{
		if (ht->array[i])
		{
			current = ht->array[i];
			while (current != NULL)
			{
				free(current->key);
				free(current->value);
				next = current->next;
				free(current);
				current = next;
			}
		}
	}
	free(ht->array);
	free(ht);
}
