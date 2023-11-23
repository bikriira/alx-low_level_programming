#include "lists.h"


/**
 * pop_listint - Deletes the head node of a listint_t linked list.
 * @head: The address of the pointer storing address of first node.
 *
 * Return: Head node’s data (n).
 */
int pop_listint(listint_t **head)
{
	int deleted_n;
	listint_t *old_head;

	if (*head == NULL)
		return (0);
	old_head = *head;
	deleted_n = (*head)->n;
	*head = (*head)->next;
	free(old_head);
	return (deleted_n);
}
