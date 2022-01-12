#include "monty.h"

/**
 *_push - pushes an element to the stack.
 *@arr: array with tokens
 *@stack: stack
 *@line_number: line number
 */

void _push(char **arr, stack_t **stack, unsigned int line_number)
{
	int i = 0;
	char *value = arr[1];

	if (value == NULL)
	{
		fprintf(stderr, "L<%d>: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	for (i = 0; value[i]; i++)
	{
		if (value[0] < '0' || value[0] > '9')
		{
			fprintf(stderr, "L<%d>: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	add_nodeint(stack, atoi(arr[1]));
}
