#include "lists.h"


/**
 * free_dlistint - Frees a dlistint_t list
 * @head: The list's head
 *
 * Return: Void
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *prev_node;

	if (head == NULL)
		return
	while (head->next != NULL)
	{
		prev_node = head;
		head = head->next;
		free(prev_node);
	}
	free(head);

}
