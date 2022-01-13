#include "monty.h"
/**
 *
 */

void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if(!*stack)
	{
		fprintf(stderr, "L<%d>: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = tmp->next;
	*stack = tmp;
}
