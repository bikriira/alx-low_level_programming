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
	{
		printf("{}\n");
		return;
	}

	printf("{");
	for  (i = 0; i < ht->size; i++)
	{
		if (ht->array[i])
		{
			if (execute == 1)
				printf(", ");

			printf("'%s': '%s'", ht->array[i]->key, ht->array[i]->value);
			if (ht->array[i]->next != NULL)
			{
				current = ht->array[i]->next;
				while (current != NULL)
				{
					printf("'%s': '%s'", ht->array[i]->key, ht->array[i]->value);
					if (current->next != NULL)
						printf(", ");
					current = current->next;
				}
			}
			execute = 1;
		}
	}
	printf("}\n");
}
