#include "lists.h"

/**
 * free_list -  frees a list_t list.
 * @head: The list_t list.
 *
 * Return: Void
 */
void free_list(list_t *head)
{
	list_t *next_node;

	while (head != NULL)
	{
		next_node = head->next;
		free(head->str);
		free(head);
		head = next_node;
	}
}
