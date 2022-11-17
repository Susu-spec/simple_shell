#include "shell.h"

/**
 * _getline - reads user input from fd and stores in buffer line
 * @fd: buffer for user input
 * Return: buffer with user input
 */
/* Note: stdin is a file descriptor/file pointer */

char *_getline(FILE *fd)
{
	char *line;
	ssize_t read;
	size_t len;

	line = NULL;
	len = 0;
	read = getline(&line, &len, fd);
	if (read == -1)
	{
		free(line);
		exit(EXIT_SUCCESS);
	}

	return (line);
}
