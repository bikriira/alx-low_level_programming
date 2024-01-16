#include "lists.h"


/**
 * add_dnodeint - Adds a new node at the beginning of a dlistint_t list
 * @head: The Address of the list's head
 * @n: The number to be stored in the new node
 *
 * Return: The address of the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *my_node = malloc(sizeof(dlistint_t));

	if (my_node == NULL)
		return (NULL);

	my_node->n = n;
	my_node->prev = NULL;

	if (*root == NULL)
		my_node->next = NULL;
	else
		my_node->next = *root;

	*root = my_node;

	return (*root);
}
