#include "shell.h"
/**
 * tokenizer - Tokenizes a string.
 * @buffer: The string.
 * @delim: The delimiter character to tokenize the string by.
 * Return: A pointer to an array containing the tokenized words.
 */
char **tokenizer(char *buffer, const char *delim)
{
	char *token = NULL, **commands = NULL;
	size_t buffersize = 0;
	int index = 0;

	if (buffer == NULL)
		return (NULL);
	buffersize = _strlen(buffer);
	commands = malloc(sizeof(char *) * (buffersize + 1));
	if (commands == NULL)
	{
		perror("Buffer allocation failed!");
		free(buffer);
		free_all(commands);
		exit(EXIT_FAILURE);
	}
	token = strtok(buffer, delim);
	while (token != NULL)
	{
		commands[index] = malloc(sizeof(char) * (_strlen(token) + 1));
		if (commands[index] == NULL)
		{
			perror("Bufer allocation failed!");
			free_all(commands);
			return (NULL);
		}
		_strcpy(commands[index], token);
		token = strtok(NULL, delim);
		index++;
	}
	commands[index] = NULL;
	return (commands);
}
