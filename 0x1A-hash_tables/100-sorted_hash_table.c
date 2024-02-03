#include "hash_tables.h"


/**
 * shash_table_create - Creates the hash table
 * @size: The size of the table,
 *	array(conatins the pointer to the elements)
 *
 * Return: Pointer to the table created
 */
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


/**
 * shash_table_set - Adds an element to the hash table and to the sorted list
 * @ht: The hash table
 * @key: The key of the element
 * @value: The value of the element
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index = key_index((const unsigned char *)key, ht->size);
	shash_node_t *element = malloc(sizeof(shash_node_t));

	if (element == NULL || strlen(key) == 0 || ht == NULL)
		return (0);
	element->key = strdup(key);
	element->value = strdup(value);
	if (element->key == NULL || element->value == NULL)
		return (0);
	element->next = element->sprev = element->snext = NULL;

	if (ht->array[index] == NULL)
	{
		ht->array[index] = element;
	}
	else if (strcmp(ht->array[index]->key, key) == 0)
	{
		free(ht->array[index]->value);
		ht->array[index]->value = strdup(value);
		if ((ht->array[index]->value) == NULL)
			return (0);
		free(element->key);
		free(element->value);
		free(element);
	}
	else
	{
		element->next = ht->array[index];
		ht->array[index] = element;
	}
	place_in_sorted_list(ht, element);

	return (1);
}


/**
 * place_in_sorted_list - put an element in the list, but sorted
 * @ht: The hash table
 * @element: The element to be placed
 *
 * Return: Void
 */
void place_in_sorted_list(shash_table_t *ht, shash_node_t *element)
{
	shash_node_t *current;

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
			return;
		}
		while (current->snext != NULL)
		{
			if (strcmp(current->snext->key, element->key) >= 0)
			{
				element->snext = current->snext;
				element->sprev = current;
				current->snext->sprev = element;
				current->snext = element;
				return;
			}
			current = current->snext;
		}
		element->sprev = current;
		current->snext = element;
		ht->stail = element;
	}
}


/**
 * shash_table_get - Retrieves the value in the hash table
 * @ht: The hash table
 * @key: The key to look for
 *
 * Return: The value of the key passed
 */
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


/**
 * table_print_helper - Used to print the table based on the sorted list,
 *						either normal or reverse order
 * @ht: The hash table
 * @reverse: used to know the printing order(1:reverse on, 0:reverse off)
 *
 * Return: Void
 */
void table_print_helper(const shash_table_t *ht, int reverse)
{
	int execute = 0;
	shash_node_t *current;

	if (ht->shead == NULL)
		return;

	printf("{");

	/* Choose head or tail based on reverse flag */
	current = reverse ? ht->stail : ht->shead;

	while (current != NULL)
	{
		if (execute == 1)
			printf(", ");
		printf("'%s': '%s'", current->key, current->value);
		execute = 1;

		/* Traverse based on reverse flag */
		current = reverse ? current->sprev : current->snext;
	}
	printf("}\n");
}


/**
 * shash_table_print - Print the hash table using the sorted linked list
 * @ht: The hash table
 *
 * Return: Void
 */
void shash_table_print(const shash_table_t *ht)
{
	/* Call the helper function with reverse flag as 0 */
	table_print_helper(ht, 0);
}


/**
 * shash_table_print_rev - Print the hash tables key/value pairs in reverse
 *							order,using the sorted linked list
 * @ht: The hash table
 *
 * Return: Void
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	/* Call the helper function with reverse flag as 1 */
	table_print_helper(ht, 1);
}


/**
 * shash_table_delete - Frees the table correctly
 * @ht: The hash table
 *
 * Return: Void
 */
void shash_table_delete(shash_table_t *ht)
{
	unsigned long int i;
	shash_node_t *current, *next;

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
