#include "headers.h"

/**
 * executor - Function to execute a program in background.
 * @aop: (Array of pointers) wich contain the arguments
 * of the executed program.
 * @path: Contain the path where the program will be executed.
 * @size: Size of pointers array. (Array of pointers - **aop)
 * Return: Success (0), Program correctly executed and memory freed.
*/

int executor(char **aop, const char *path, int size)
{
	pid_t childID = fork(), r_value = 0;
	int wstatus = 0;

	if (aop && path && size != 0)
	{
		if (childID < 0)
		{
			perror("fork() error");
			return (-1);
		}

		if (childID == 0)
		{
			r_value = execve(path, aop, NULL);
		}

		else
		{
			waitpid(childID, &wstatus, 0);
		}

		if (r_value < 0)
		{
			printf("%s: %d: %s: not found\n", path, errno, aop[1]);
			/* execve() only returns on error */
			return (WEXITSTATUS(wstatus));
		}
		else
		{
			return (WEXITSTATUS(wstatus));
		}
	}
	perror("Executor can't find aop, path or size.");
	return (-1);
}
