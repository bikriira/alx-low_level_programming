#include "lists.h"


/**
 * sum_dlistint - Adds all the data (n) of a dlistint_t linked list
 * @head: The list's head
 *
 * Return: Sum of all the data (n) of a dlistint_t linked list
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	if (head == NULL)
		return (0);

	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}
