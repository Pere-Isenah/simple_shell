#include "headers.h"

/**
 * _strlen - Function to find the length of a string.
 * @str: String to be counted.
 * Return: Then length of the string whitout the las character '\0'.
*/

int _strlen(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{}

	return (i);
}
