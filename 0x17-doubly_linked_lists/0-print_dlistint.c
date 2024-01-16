#include "lists.h"


/**
 * print_dlistint - Prints all the elements of a dlistint_t list
 * @h: Address to the first node
 *
 * Return: Number of nodes
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t count = 0;
	curr = *h;

	while (curr != NULL)
	{
		printf("%d", curr->n);
		count++;
		curr = curr->next;
	}
	return count;
}
