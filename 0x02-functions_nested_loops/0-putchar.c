#include "main.h"

/**
 * main - consists of codes that prints _putchar, followed by a new line.
 * Return : 0
 */

void main()
{
	char word[] = "_putchar";

	while (true)
	{
		if (word[i] != "\0")
		{
			_putchar(word[i]);
			i++;
		}
		else
		{
			break;
		}
	return 0;
	}
}
