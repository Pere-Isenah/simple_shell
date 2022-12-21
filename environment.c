#include "shell.h"
/**
 * _printenv - A function that prints all enviromental variables.
 * @env: The pointer to enviromental variables.
 * Return: Nothing.
 */
void _printenv(char **env)
{
	size_t index = 0, length = 0;

	while (env[index])
	{
		length = _strlen(env[index]);
		write(STDOUT_FILENO, env[index], length);
		write(STDOUT_FILENO, "\n", 1);
		index++;
	}
}
/**
 * _getpath - A function to gets the full value from.
 * enviromental variable PATH.
 * @env: The pointer to enviromental variables.
 * Return: All tokenized pathways for commands.
 */
char **_getpath(char **env)
{
	char *pathvalue = NULL, **pathway = NULL;
	unsigned int index = 0;

	pathvalue = strtok(env[index], "=");
	while (env[index])
	{
		if (_strcmp(pathvalue, "PATH"))
		{
			pathvalue = strtok(NULL, " \n");
			pathway = tokenizer(pathvalue, ":");
			return (pathway);
		}
		index++;
		pathvalue = strtok(env[index], "=");
	}
	return (NULL);
}
