#include "main.h"


/**
 * _strlen - Counts the number of character in the string
 * @s: Pointer to the string to be worked on
 *
 * Return: The number of string chars
 */
int _strlen(char *s)
{
	int counter = 0;

	while (*s)
	{
		s++;
		counter++;
	}
	return (counter);
}
