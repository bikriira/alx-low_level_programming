#include "lists.h"


/**
 * add_nodeint_end - Adds a new node at the end of a listint_t list.
 * @head: The address of the list to work on.
 * @n: The value of the the node to be added.
 *
 * Return: The address of the new element, or NULL if it failed.
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new_node = malloc(sizeof(listint_t)), *curr = *head;

	if (!new_node)
		return (NULL);
	new_node->n = n;
	new_node->next = NULL;
	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	curr->next = new_node;
	return (new_node);
}
