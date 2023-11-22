#include "lists.h"

/**
 * free_listint - Frees a listint_t list.
 * @head: The list to work on
 *
 * Return: Void
 */
void free_listint(listint_t *head)
{
	listint_t *curr = head, *next_del;

	while (curr)
	{
		next_del = curr->next;
		free(curr);
		curr = next_del;
	}
}
