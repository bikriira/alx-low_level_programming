#include "lists.h"


/**
 * insert_nodeint_at_index - Inserts a new node to a listint_t
 *                           list at a given position.
 * @head: A pointer to the address of the
 *        head of the listint_t list.
 * @idx: The index of the listint_t list where the new
 *       node should be added - indices start at 0.
 * @n: The integer for the new node to contain.
 *
 * Return: If the function fails - NULL.
 *         Otherwise - the address of the new node.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_node, *curr, *old_curr_next;
	unsigned int counter = 0;

	new_node = malloc(sizeof(listint_t));
	if (!new_node && !(*head))
		return (NULL);
	curr = *head;
	new_node->n = n;
	while (curr)
	{
		if (counter + 1 == idx || idx == 0)
		{
			old_curr_next = curr->next;
			curr->next = new_node;
			new_node->next = old_curr_next;
			return (new_node);
		}
		counter++;
		curr = curr->next;
	}
	return (NULL);
}
