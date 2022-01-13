#include "monty.h"

/**
 * tokenizer - tokenizes the input received.
 *@buffer: string received from input.
 *@separator: separetor character.
 *Return: returns an array of strings.
 */

char **tokenizer(char *buffer, char *separator)
{
	int i = 0, n = 0, count = 1;
	char **tokenized = NULL;
	char *token = NULL;

	while (buffer[n])
	{
		if (buffer[n] == 0 || buffer[n] == '#')
		{
			return (NULL);
		}
		if (buffer[n] == separator[0])
		{
			if (buffer[n + 1] && buffer[n + 1] != separator[0])
				count++;
		}
		n++;
	}
	token = strtok(buffer, separator);
	if (token == NULL)
		return (NULL);
	tokenized = malloc(sizeof(char *) * (count + 1));
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
