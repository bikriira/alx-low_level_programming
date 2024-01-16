#include "lists.h"


/**
 * print_dlistint - Return the number of nodes(elements) in a list
 * @h: Address to the first node
 *
 * Return: Number of nodes
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		count++;
		h = h->next;
	}
	return (count);
}
