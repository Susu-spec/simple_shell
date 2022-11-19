#include "shell.h"

/**
 * builtin_execute - executes the built-in function
 * @tokens: arguments passed for execution
 * Return: tokens
 */

int builtin_execute(char **tokens)
{
	int status;
	unsigned int length;
	unsigned int num;
	unsigned int i;

	built_s builtin[] = {
		{"exit", shell_exit},
		{"env", shell_env},
		{NULL, NULL}
	};

	if (tokens[0] == NULL)
		return (1);
	num = shell_num_builtins(builtin);
	length = _strlen(tokens[0]);
	for (i = 0; i < num; i++)
	{
		if (_strcmp(tokens[0], builtin[i].name, length) == 0)
		{
			status = (builtin[i].p)();
			return (status);
		}
	}
	return (1);
}

/**
 * shell_num_builtins - counts number of builtins
 * @builtin: builtin struct array
 * Return: number of builtins
 */

int shell_num_builtins(built_s builtin[])
{
	unsigned int i;

	i = 0;
	while (builtin[i].name != NULL)
		i++;

	return (i);
}
