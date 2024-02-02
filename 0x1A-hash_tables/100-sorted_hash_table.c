#include "hash_tables.h"



shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *table;
	unsigned long int i;

	table = malloc(sizeof(shash_table_t));
	if (table == NULL)
		return (NULL);

	table->size = size;

	table->array = malloc(sizeof(shash_node_t *) * size);
	if (table->array == NULL)
		return (NULL);
	/* Set table->arrays elemnts all to null by default */
	for (i = 0; i < size; i++)
		table->array[i] = NULL;
	
	table->shead = NULL;
	table->stail = NULL;
	
	return (table);
}



int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index = key_index((const unsigned char *)key, ht->size);
	shash_node_t *element = malloc(sizeof(shash_node_t)), *current;

	if (element == NULL || strlen(key) == 0 || ht == NULL)
		return (0);
	element->key = strdup(key);
	element->value = strdup(value);
	element->next = element->sprev = element->snext = NULL;
	if (ht->array[index] == NULL)
	{
		ht->array[index] = element;
	}
	else if (strcmp(ht->array[index]->key, key) == 0)
	{
		free(ht->array[index]->value);
		ht->array[index]->value = strdup(value);
		free(element->key);
		free(element->value);
		free(element);
	}
	else
	{
		element->next = ht->array[index];
		ht->array[index] = element;
	}


	if (ht->shead == NULL)
	{
		ht->shead = ht->stail = element;
	}
	else
	{
		current = ht->shead;
		if (strcmp(current->key, element->key) >= 0)
		{
			element->snext = current;
			current->sprev = element;
			ht->shead = element;
			return (1);
		}
		while (current->snext != NULL)
		{
			if (strcmp(current->snext->key, element->key) >= 0)
			{
				element->snext = current->snext;
				element->sprev = current;
				current->snext->sprev = element;
				current->snext = element;
				return (1);
			}
			current = current->snext;
		}
		element->sprev = current;
		current->snext = element;
		ht->stail = element;
	}
	return (1);
}



char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int elem_index;
	shash_node_t *current;

	if (ht == NULL || key == NULL || strlen(key) == 0)
		return (NULL);

	elem_index = key_index((unsigned char *)key, ht->size);
	current = ht->array[elem_index];
	while (current != NULL)
	{
		if (strcmp(current->key, key) == 0)
			return (current->value);
		current = current->next;
	}
	return (NULL);
}


/*void shash_table_print(const shash_table_t *ht)
{
	int execute = 0;
	shash_node_t *current;

	if (ht->shead == NULL)
		return;

	printf("{");
	current = ht->shead;
	while (current != NULL)
	{
		if (execute == 1)
			printf(", ");
		printf("'%s': '%s'", current->key, current->value);
		execute = 1;
		current = current->snext;
	}
	printf("}\n");
}
void shash_table_print_rev(const shash_table_t *ht)
{
    int execute = 0;
    shash_node_t *current;
    
    if (ht->shead == NULL)
        return;
    
    printf("{");
    current = ht->shead;
    while (current != NULL)
    {
        if (execute == 1)
            printf(", ");
        printf("'%s': '%s'", current->key, current->value);
        execute = 1;
        current = current->snext;
    }
    printf("}\n");
}*/

void table_print_helper(const shash_table_t *ht, int reverse)
{
	int execute = 0;
	shash_node_t *current;

	if (ht->shead == NULL)
		return;

	printf("{");
	current = reverse ? ht->stail : ht->shead; /* Choose head or tail based on reverse flag */
	while (current != NULL)
	{
		if (execute == 1)
    		printf(", ");
		printf("'%s': '%s'", current->key, current->value);
		execute = 1;
		current = reverse ? current->sprev : current->snext; /* Traverse based on reverse flag */
    }
	printf("}\n");
}

void shash_table_print(const shash_table_t *ht)
{
	table_print_helper(ht, 0); /* Call the helper function with reverse flag as 0 */
}

void shash_table_print_rev(const shash_table_t *ht)
{
	table_print_helper(ht, 1); /* Call the helper function with reverse flag as 1 */
}


















