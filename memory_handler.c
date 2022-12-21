#include "shell.h"
/**
 * free_all - A function that frees all the memory allocated for command.
 * @command: The pointer to allocated memory to free.
 * Return: Nothing.
 */
void free_all(char **command)
{
	size_t index = 0;

	if (command == NULL)
		return;
	while (command[index])
	{
		free(command[index]);
		index++;
	}
	if (command[index] == NULL)
		free(command[index]);
	free(command);
}
/**
 * free_n_exit - A function that frees all the memory allocated and exit.
 * @command: The pointer to allocated command memory to free.
 * Return: Nothing.
 */
void free_n_exit(char **command)
{
	size_t index = 0;

	if (command == NULL)
		return;
	while (command[index])
	{
		free(command[index]);
		index++;
	}
	if (command[index] == NULL)
		free(command[index]);
	free(command);
	exit(EXIT_FAILURE);
}
