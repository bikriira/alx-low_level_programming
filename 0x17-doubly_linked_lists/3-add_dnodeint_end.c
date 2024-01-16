#include "lists.h"


/**
 * add_dnodeint_end - Adds a new node at the end of a dlistint_t list
 * @head: the address of the list's head
 * @n: The value to be stored inside the new node's n
 *
 * Return: The address of the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *curr = *head;
	dlistint_t *my_node = malloc(sizeof(dlistint_t));

	if (my_node == NULL)
		return (NULL);

	my_node->n = n;
	my_node->next = NULL;

	if (curr == NULL)
	{
		my_node->prev = NULL;
		*head = my_node;
		return (my_node);
	}

	while (curr->next != NULL)
		curr = curr->next;

	curr->next = my_node;
	my_node->prev = curr;

	return (my_node);
}
