#include "shell.h"

/**
 * search - searches directories in PATH for command
 * @command: to searched
 * @fullpath: full path of command to execute
 * @path: full PATH variable
 * Return: pointer to full_path
 */

char *search(char *command, char *fullpath, char *path)
{
	unsigned int command_length, path_length, original_path_length;
	char *path_copy, *token;

	command_length = _strlen(command);
	original_path_length = _strlen(path);
	path_copy = malloc(sizeof(char) * original_path_length + 1);
	if (path_copy == NULL)
	{
		errors(3);
		return (NULL);
	}
	_strcpy(path_copy, path);
	/* copy PATH directory and command and check if it matches */
	token = strtok(path_copy, ":");
	if (token == NULL)
		token = strtok(NULL, ":");
	while (token != NULL)
	{
		path_length = _strlen(token);
		fullpath = malloc(sizeof(char) * (path_length + command_length + 2));
		if (fullpath == NULL)
		{
			errors(3);
			return (NULL);
		}
		_strcpy(fullpath, token);
		fullpath[path_length + command_length + 1] = '\0';
		if (access(fullpath, X_OK) != 0)
		{
			free(fullpath);
			fullpath = NULL;
			token = strtok(NULL, ":");
		}
		else
			break;
	}
	free(path_copy);
	return (fullpath);
}
