#include "shell.h"
/**
 * error_messages - A function that prints message not found.
 * @name: The name of the shell.
 * @cycles: Number of cycles.
 * @command: The pointer to tokenized command.
 * Return: Nothing.
 */
void error_messages(char *name, int cycles, char **command)
{
	char c;

	c =  cycles + '0';
	write(STDOUT_FILENO, name, _strlen(name));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, &c, 1);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, command[0], _strlen(command[0]));
	write(STDOUT_FILENO, ": not found\n", 12);
}
