#include "headers.h"

/**
 * decision_taker - Function to take a decision if the first agrument[0]
 * is a path e."/bin" or is a program to be found e."ls".
 * @arguments: Pointers array with the values entered by
 * the user trough getline().
 * @size: Size of pointers array.
 * @_env: Have the environment from where is executed the program.
 * - env will be pased as an argument of path_finder()
 * @wstatus: Return status of the las program executed.
 * Return: (0) Success, take a expected decition.
  **/

int decision_taker(char **arguments, int size, char **_env, int *wstatus)
{
	char *comdenv = "env";
	int i = 0;

	if (arguments && _env && size != 0)
	{
		if ((**arguments == '/') | (**arguments == '.'))
		{
			i = executor(arguments, arguments[0], size);
			*wstatus = i;
			return (*wstatus);
		}
		else
		{
			if ((_strcmp(arguments[0], comdenv)) == 0)
			{
				printenv(_env);
				return (0);
			}
			else
			{
				path_finder(arguments, size, _env, wstatus);
				return (0);
			}
		}
	}
	perror("Unable to find arguments, size or envp arguments.");
	return (-1);
}
