#include "lists.h"


/**
 * sum_listint - prints all the element's sum of listint_t list.
 * @head: The list tobe worked on.
 *
 * Return: The sum of node's n value.
 */
int sum_listint(listint_t *head)
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
