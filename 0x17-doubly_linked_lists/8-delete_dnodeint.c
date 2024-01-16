#include  "lists.h"


/**
 * delete_dnodeint_at_index - Deletes node at a given position
 * @head: The address of list's head
 * @index: Index of the node to delete
 *
 * Return: The address of the new node, or NULL if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	unsigned int counter = 0;
	dlistint_t *curr = *head, *node_to_delete;

	if (curr == NULL)
		return (-1);

	if (index == 0)
	{
		node_to_delete = curr;

		if (curr->next != NULL)
			curr->next->prev = NULL;

		free(node_to_delete);
		*head = curr->next;

		return (1);
	}

	while (curr->next != NULL)
	{
		if (counter + 1 == index)
		{
			node_to_delete = curr->next;
			curr->next = node_to_delete->next;

			if (node_to_delete->next != NULL)
				node_to_delete->next->prev = curr;

			free(node_to_delete);
			return (1);
		}
		counter++;
		curr = curr->next;
	}

	return (-1);
}
