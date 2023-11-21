#include "lists.h"
#include <stdio.h>

/**
 * print_list - Prints all the elements of a list_t list.
 * @h: The list_t list.
 *
 * Return: The number of nodes in h.
 */

size_t print_list(const list_t *h)
{
	size_t node_count = 0;
	
	while (h != NULL)
	{
		if (h->str != NULL)
			printf("[%d] %s", h->len, h->str);
		else
			printf("[0] (nil)");
		h = h->next;
		node_count++;
	}

	return (node_count);
}
