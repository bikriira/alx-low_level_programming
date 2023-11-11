#include "main.h"

/**
 * print_alphabet_x10 - prints the alphabet, in lowercase, followed by a new line.
 * Return: nothing
 */
 
void print_alphabet_x10(void)
{
	int row;

	for (row = 0; row < 10; row++)
	{
        	char i;

	        for (i = 'a'; i <= 'z'; i++)
        	        _putchar(i);
	        _putchar('\n');
	}
}
