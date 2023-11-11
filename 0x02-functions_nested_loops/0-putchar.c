#include "main.h"

/**
 * main - consists of codes that prints _putchar, followed by a new line.
 * Return : 0
 */

int main()
{
	char word[] = "_putchar";
	int i;

	i = 0;
	while (1)
	{
		if (word[i] != '\0')
		{
			_putchar(word[i]);
			i++;
		}
		else
		{
			break;
		}
	}
	_putchar('\n');
	return (0);
}
