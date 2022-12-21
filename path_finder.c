#include "headers.h"

#define UNUSED(x) (void)(x)


/**
 * path_finder - Function to fin the $PATH in the program environment.
 * @aop: (Array of poiters), arguments of the program tu execute.
 * @size: Size of the (Array of pointers - aop).
 * @_env: Current environment where the program is executed.
 * @wstatus: Return status of the las program executed.
 * Return - void.
 */

void path_finder(char **aop, int size, char **_env, int *wstatus)
{
	char **path = NULL, temp[3000];
	char match[6] = "PATH=";
	int i = 0, ienv = 0, strcount = 0, len = 0, result = 0;

	UNUSED(result);

	while (*_env)
	{
		if (_env[ienv])
		{
			_strncpy(temp, _env[ienv], 1);
			ienv++;
		}

		while (temp[i] == match[i])
		{
			i++;
		}

		if (i == 5)
		{
			len = _strlen(temp);
			path = space_organizer(temp, "PATH=:\n", len, &strcount);
			result = one_finxer(aop, path, size, strcount, wstatus);
			*wstatus = result;
			a_liberator(path, strcount);
			return;
		}
	}
}
