#include "monty.h"

/**
 * tokenizer - tokenizes the input received.
 *@buffer: string received from input.
 *@separator: separetor character.
 *Return: returns an array of strings.
 */

char **tokenizer(char *buffer, char *separator)
{
	int i = 0;
	char **tokenized = NULL;
	char *token = NULL;
	size_t size = 1024;

	token = strtok(buffer, separator);
	if (token == NULL)
		return (NULL);
	tokenized = malloc(sizeof(char *) * size);
	if (tokenized == NULL)
		return (NULL);

	while (token)
	{
		tokenized[i] = token;
		token = strtok(NULL, separator);
		i++;
	}

	tokenized[i] = NULL;
	return (tokenized);
}
