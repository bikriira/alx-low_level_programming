#include "main.h"

/**
 * read_textfile - reads a text file and prints the letters
 * @filename: filename.
 * @letters: numbers of letters printed.
 *
 * Return: numbers of letters printed.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fdd;
	ssize_t nd, nr;
	char *buff;

	if (!filename)
		return (0);

	fdd = open(filename, O_RDONLY);

	if (fdd == -1)
		return (0);

	buff = malloc(sizeof(char) * (letters));
	if (!buff)
		return (0);

	nd = read(fdd, buff, letters);
	nwr = write(STDOUT_FILENO, buff, nd);

	close(fdd);

	free(buff);

	return (nr);
}
