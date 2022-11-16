#include "shell.h"

/**
 * get_env - gets an environment variable
 * @name: environment variable to get
 * Return: pointer to environment variable, NULL if none exists
 */

char *_get_env(const char *name)
{
	char **environ_copy;
	char *variable, *value, *path;
	int compare;
	unsigned int path_length, environ_length, length, i;

	environ_length = 0;
	while (environ[environ_length] != NULL)
	{
		variable = environ_copy[i];
		compare = _strcmp((char *)name, variable, length);
		if (compare == 1)
		{
			value = strtok(variable, "=");
			value = strtok(NULL, "\n ");
			if (value == '\0')
			{
				errors(4);
				exit(EXIT_FAILURE);
			}
			
			path_length = _strlen(value);
			path= malloc(sizeof(char) * path_length + 1);
			if (path == NULL)
			{
				errors(3);
				return (NULL);
			}
			path = _strcpy(path, value);
			free_dp(environ_copy, environ_length);
			return (path);
		}
		i++;
	}
	return (NULL);
}
