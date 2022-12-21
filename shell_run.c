#include "shell.h"
/**
 * tipresh_prompt - A function that prints the prompt
 * Return: Nothing.
 */
void tipresh_prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "tipresh$ ", 9);
}
/**
 * ctrl_c_handler - A function to handle Ctr + C signal.
 * @signals: The signal to handle.
 * Return: Nothing.
 */
void ctrl_c_handler(int signals)
{
	(void)signals;
	write(STDOUT_FILENO, "\ntipresh$ ", 10);
}
/**
 * _EOF - A function that checks if buffer is EOF
 * @buffer: The pointer to the input string.
 * Return: Nothing
 */
void _EOF(char *buffer)
{
	if (buffer)
	{
		free(buffer);
		buffer = NULL;
	}
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
	free(buffer);
	exit(EXIT_SUCCESS);
}
/**
 * exit_shell - A function that exits the shell.
 * @command: The pointer to tokenized command.
 * Return: Nothing.
 */
void exit_shell(char **command)
{
	int stat_us = 0;

	if (command[1] == NULL)
	{
		free_all(command);
		exit(EXIT_SUCCESS);
	}
	stat_us = _atoi(command[1]);
	free_all(command);
	exit(stat_us);
}
