#include "lists.h"


/**
 * get_dnodeint_at_index - returns the nth node's address in linked list
 * @head: The list's head
 * @index: The index of the node, starting from 0
 *
 * Return: The nth node of a dlistint_t linked list,
 * if the node does not exist, return NULL
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int curr_index = 0;

	if (head == NULL)
		return (NULL);

	while (head != NULL)
	{
		if (curr_index == index)
			return (head);
		curr_index++;
		head = head->next;
	}

	return (NULL);
}
