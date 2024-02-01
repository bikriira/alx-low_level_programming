#include "hash_tables.h"


/**
 * hash_table_print - Print the hash table in order
 * @ht: The hash table
 *
 * Return: Void
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	int execute = 0;
	hash_node_t *current;

	if (ht == NULL)
		return;

	printf("{");
	for  (i = 0; i < ht->size; i++)
	{
		if (ht->array[i])
		{
			current = ht->array[i];
			while (current != NULL)
			{
				if (execute == 1)
					printf(", ");
				printf("'%s': '%s'", current->key, current->value);
				execute = 1;
				current = current->next;
			}
		}
	}
	printf("}\n");
}
