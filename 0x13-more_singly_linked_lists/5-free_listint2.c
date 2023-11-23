#include "lists.h"

/**
 * free_listint2 - Frees a listint_t list and set head to null.
 * @head: The address of the pointer with address of first node.
 *
 * Return: Void
 */
void free_listint2(listint_t **head)
{
	listint_t *curr = *head, *next_del;

	while (curr)
	{
		next_del = curr->next;
		free(curr);
		curr = next_del;
	}
	*head = NULL;
}
