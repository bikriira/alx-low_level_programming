#include "lists.h"


/**
 * add_node_end - Adds a new node at the end of a list_t list.
 * @head: The list_t list.
 * @str: The sring to be added within new created node.
 *
 * Return: The address of the new element, or NULL if it failed.
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_node = malloc(sizeof(list_t));
	list_t *curr = *head;

	if (new_node == NULL)
		return (NULL);
	new_node->str = strdup(str);
	new_node->len = strlen(str);
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
