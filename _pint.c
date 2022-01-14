#include "monty.h"

/**
 *_pint - prints the value at the top of the stack, followed by a new line.
 *@stack: stack
 *@line_number: line number
 */

void _pint(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;

	tmp = *stack;
	if (!tmp)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", tmp->n);
}
