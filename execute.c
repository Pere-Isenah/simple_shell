#include "shell.h"
/**
 * execute - A function that executes a command.
 * @command: The pointer to tokienized command
 * @name: The name of the shell.
 * @env: The pointer to the enviromental variables.
 * @cycles: Number of executed cicles.
 * Return: Nothing.
 */
void execute(char **command, char *name, char **env, int cycles)
{
	char **pathways = NULL, *full_path = NULL;
	struct stat st;
	unsigned int i = 0;

	if (_strcmp(command[0], "env") != 0)
		_printenv(env);
	if (stat(command[0], &st) == 0)
	{
		if (execve(command[0], command, env) < 0)
		{
			perror(name);
			free_n_exit(command);
		}
	}
	else
	{
		pathways = _getpath(env);
		while (pathways[i])
		{
			full_path = _strcat(pathways[i], command[0]);
			i++;
			if (stat(full_path, &st) == 0)
			{
				if (execve(full_path, command, env) < 0)
				{
					perror(name);
					free_all(pathways);
					free_n_exit(command);
				}
				return;
			}
		}
		error_messages(name, cycles, command);
		free_all(pathways);
	}
}
