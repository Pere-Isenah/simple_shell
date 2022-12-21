#include "headers.h"

/**
 * a_liberator - Function to free an array of pointers.
 * @aop: (Array of pointers) to be freed.
 * @size: Size of the array.
 * Return - void.
*/

void a_liberator(char **aop, int size)
{
	int i = 0;

	if (aop && size != 0)
	{
		while (aop[i])
		{
			free(aop[i]);
			i++;
		}

		free(aop);
		return;
	}
	else
	{
		perror("Array or size not received | That pointers are already free.");
		return;
	}
}
