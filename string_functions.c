#include "shell.h"

/**
 * _strcmp - compares two strings to check if equal
 * @name: user input
 * @variable: variable to compare against
 * @length: length of name
 * Return: 1 if strings are equal, -1 if not
 */

int _strcmp(char *name, char *variable, unsigned int length)
{
	unsigned int var_length;
	unsigned int i;

	var_length = _strlen(variable);
	if (var_length != length)
		return (-1);

	i = 0;
	while (name[i] != '\0' && variable[i] != '\0')
	{
		if (name[i] != variable[i])
			return (1);
		i++;
	}
	return (0);
}

/**
 * _strncmp - compares..
 * @length: number of bytes
 * @name: of user input
 * @variable: to variable
 * Return: 1 if equal, -1 if not
 */

int _strncmp(char *name, char *variable, unsigned int length)
{
	unsigned int i;

	i = 0;
	while (i < length)
	{
		if (name[i] != variable[i])
			return (-1);
		i++;
	}
	return (1);
}

/**
 * _strcpy - copies string pointed to by src to dest buffer
 * @dest: string destination
 * @src: string source
 * Return: the pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	int i;
	int j = _strlen(src);

	for (i = 0; i <= j; i++)
		dest[i] = src[i];
	return (dest);
}

/**
 * _strlen - calculates length of string, excludes '\0'
 * @s: string to be evaluated
 * Return: length of string
 */

int _strlen(char *s)
{
	int i;

	i = 0;

	while (s[i] != '\0')
		i++;

	return (i);
}
