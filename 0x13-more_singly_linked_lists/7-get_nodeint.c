#include "lists.h"


/**
 * get_nodeint_at_index - Returns the nth node of a listint_t linked list.
 * @head: The list to worrk on.
 * @index: The index of the node to return.
 *
 * Return: The node or null if node does not exist.
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *curr = head;
	unsigned int counter = 0;

	while (curr)
	{
		if (counter == index)
			return (curr);
		counter++;
		curr = curr->next;
	}
	return (NULL);
}
