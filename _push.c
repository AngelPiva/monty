#include "monty.h"

/**
 *_push - pushes an element to the stack.
 *@arr: array with tokens
 *@stack: stack
 *@line_number: line number
 *Return: 0 in success, -1 in failure
 */

int _push(char **arr, stack_t **stack, unsigned int line_number)
{
	int i = 0;
	char *value = arr[1];

	if (value == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		return (-1);
	}
	for (i = 0; value[i]; i++)
	{
		if ((value[i] < '0' || value[i] > '9') && (value[0] != '-'))
		{
			if (value[i] < '0' || value[i] > '9')
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				return (-1);
			}
		}
	}
	add_nodeint(stack, atoi(arr[1]));
	return (0);
}
