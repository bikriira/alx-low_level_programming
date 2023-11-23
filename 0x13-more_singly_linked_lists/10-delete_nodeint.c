#include "lists.h"


/**
 * delete_nodeint_at_index - Deletes the node at a given
 *                           index of a listint_t list.
 * @head: A pointer to the address of the
 *        head of the listint_t list.
 * @index: The index of the node to be deleted - indices start at 0.
 *
 * Return: On success - 1.
 *         On failure - -1.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *curr, *be_deleted;
	unsigned int counter = 0;

	if (!(*head))
		return (-1);
	if (index == 0)
	{
		be_deleted = *head;
		*head = (*head)->next;
		free(be_deleted);
		return (1);
	}
	curr = *head;
	while (curr)
	{
		if (counter + 1 == index)
		{
			be_deleted = curr->next;
			curr->next = curr->next->next;
			free(be_deleted);
			return (1);
		}
		counter++;
		curr = curr->next;
	}
	return (-1);
}
