#include "shell.h"
/**
 * _strcmp - compares two strings.
 * @string1: string one.
 * @string2: string two to compare with string1.
 *
 * Return: The difference between string1 and string2.
 */
int _strcmp(char *string1, char *string2)
{
	unsigned int index = 0;

	while (string1[index])
	{
		if (string1[index] != string2[index])
			return (0);
		index++;
	}
	return (1);
}
/**
 * _strcpy - copies the string pointed to by src, including
 * terminating null byte, to the buffer pointed to by dest
 * @dest: pointer to be copied to..
 * @src: pointer to string src.
 * Return: dest
 */
char *_strcpy(char *dest, char *src)
{
	char *tmp = dest;

	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (tmp);
}
/**
 * _strcat - concatenates two strings.
 * @dest: string to be added to
 * @src: string to add.
 *
 * Return: dest
 */
char *_strcat(char *dest, char *src)
{
	int length = 0, index = 0;

	while (dest[index++])
	{
		length++;
	}
	for (index = 0; src[index] != '\0'; index++)
		dest[length++] = src[index];
	dest[length++] = '\0';
	return (dest);
}
/**
 * _strlen - returns the length of a string.
 * @string: string whose length is to be returned.
 *
 * Return: length of the string
 */
int _strlen(char *string)
{
	int length = 0;

	while (*string++)
		length++;
	return (length);
}
/**
 * _atoi - a function that converts string to integer.
 * @s: An input string.
 * Return: integer from conversion.
 */
int _atoi(char *s)
{
	int sign = 1;
	unsigned int total = 0;
	char null_flag = 0;

	if (s == NULL)
		return (0);
	while (*s)
	{
		if (*s == '-')
			sign *= -1;
		if (*s >= '0' && *s <= '9')
		{
			null_flag = 1;
			total = total * 10 + (*s - '0');
		}
		else if (*s < '0' || *s > '9')
		{
			if (null_flag == 1)
				break;
		}
		s++;
	}
	if (sign < 0)
		total = (-1 * (total));
	return (total);
}
