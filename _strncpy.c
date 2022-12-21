#include "headers.h"

/**
 * _strncpy - return the copie of one string.
 * @dest: Copy after function execution.
 * @src: Original string to bi copied.
 * @n: Number of characters in src. (UNUSED).
 * Return: The string copied (dest).
*/

char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	if (dest && src && n != 0)
	{
		for (i = 0; src[i] != '\0'; i++)
		{
			dest[i] = src[i];
		}

		dest[i] = '\0';
		return (dest);
	}
	return (NULL);
}
