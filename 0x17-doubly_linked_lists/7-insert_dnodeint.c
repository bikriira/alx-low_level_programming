#include  "lists.h"


/**
 * insert_dnodeint_at_index - Inserts a new node at a given position
 * @h: The address of list's head
 * @idx: The index that the new_node should be at
 * @n: The value to be stored in new_node's n
 *
 * Return: The address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	unsigned int counter = 0;
	dlistint_t *curr = *h, *new_node = malloc(sizeof(dlistint_t));

	if (new_node == NULL)
		return (NULL);
	new_node->n = n;

	if (idx == 0 || curr == NULL)
	{
		new_node->prev = NULL;
		new_node->next = curr;
		if (cur != NULL)
			curr->prev = new_node;
		*h = new_node;

		return (new_node);
	}

	while (curr != NULL)
	{
		if (counter + 1 == idx)
		{
			new_node->prev = curr;
			new_node->next = curr->next;

			if (curr->next != NULL)
				curr->next->prev = new_node;

			curr->next = new_node;
			return (new_node);
		}
		counter++;
		curr = curr->next;
	}

	return (NULL);
}
