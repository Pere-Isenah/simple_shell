#include "shell.h"
/**
 * main - A function that runs our shell.
 * @ac: The number of inputed arguments.
 * @av: The pointer to array of inputed arguments.
 * @env: The pointer to array of enviromental variables.
 * Return: Always 0.
 */
int main(int ac, char **av, char **env)
{
	char *buffer = NULL, **command = NULL;
	size_t buffersize = 0;
	ssize_t chars_num = 0;
	int cycles = 0;
	(void)ac;

	while (1)
	{
		cycles++;
		tipresh_prompt();
		signal(SIGINT, ctrl_c_handler);
		chars_num = getline(&buffer, &buffersize, stdin);
		if (chars_num == EOF)
			_EOF(buffer);
		else if (*buffer == '\n')
			free(buffer);
		else
		{
			buffer[_strlen(buffer) - 1] = '\0';
			command = tokenizer(buffer, " \0");
			free(buffer);
			if (_strcmp(command[0], "exit") != 0)
				exit_shell(command);
			else if (_strcmp(command[0], "cd") != 0)
				change_dir(command[1]);
			else
				launch_subprocess(command, av[0], env, cycles);
		}
		fflush(stdin);
		buffer = NULL, buffersize = 0;
	}
	if (chars_num == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
/* by Tito osadebe and precious uzoma */
