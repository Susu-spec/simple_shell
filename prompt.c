#include "shell.h"

/**
 * prompt - checks mode and prints promt if interactive
 * @fd: file descriptor/stream
 * @buf: buffer
 */

void prompt(int fd, struct stat buf)
{
	fstat(fd, &buf);

	if (S_ISCHR(buf.st_mode))
		_puts(PROMPT);
}

/**
 * _puts - writes to stdout
 * @str: string to print
 */
void _puts(char *str)
{
	unsigned int length;

	length = _strlen(str);

	write(STDOUT_FILENO, str, length);
}
