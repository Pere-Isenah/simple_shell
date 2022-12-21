#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "headers.h"

/**
 * space_organizer - Function to create a dynamic array of pointers
 * where store every argument given by user trough getilne().
 * @string: The original string to be separed into tokens with strtok().
 * @delim: The delimiter characters for strtok().
 * @len: Lenght of the entire (string).
 * @strcount: Variable where store the amount of tokens found
 * (variable needed by malloc).
 * Return: Success (Array of pointers - aop), where all tokens will be saved.
 */

char **space_organizer(char *string, const char *delim, int len, int *strcount)
{
	char *temp, *token, **aop;
	int i = 0, stlen[120];

	temp  = malloc(sizeof(char) * (len + 1));
	if (temp)
	{
		temp = _strncpy(temp, string, len);
		token = strtok(temp, delim);

		while (token != NULL)
		{
			stlen[i] = _strlen(token);
			token = strtok(NULL, delim);
			(*strcount)++;
			i++;
		}
		free(temp);
	}
	else
		perror("Buffer0 not found. (Malloc)");
	aop = malloc(sizeof(*aop) * (*strcount + 1));
	for (i = 0; i < (*strcount); i++)
		aop[i] = malloc(sizeof(char) * (stlen[i] + 1));
	aop[(*strcount)] = NULL;
	if (aop)
	{
		i = 0;
		temp = strtok(string, delim);
		aop[i] = _strncpy(aop[i], temp, (stlen[0] + 1));
		temp = strtok(NULL, delim);
		while (aop[i] && temp)
		{
			i++;
			aop[i] = _strncpy(aop[i], temp, (stlen[i] + 1));
			temp = strtok(NULL, delim);
		}
		return (aop);
	}
	return (NULL);
}
