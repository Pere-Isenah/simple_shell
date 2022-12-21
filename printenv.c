#include "headers.h"

/**
 * printenv - Function to print the current program environment.
 * @envp: Pointers array where are stored all the environment variables.
 * Return - void.
 */

void printenv(char **envp)
{
	int i = 0;

	if (envp)
	{
		while (envp[i])
		{
			write(STDOUT_FILENO, envp[i], _strlen(envp[i]));
			write(STDOUT_FILENO, "\n", 1);
			i++;
		}
		return;
	}
	perror("Unable to find envp.");
}
