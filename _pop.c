#include "monty.h"

/**
 * _pop - pops the top element
 *@stack: stack pointer
 *@line_number: line number
 */

void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (!*stack)
	{
		fprintf(stderr, "L<%d>: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = tmp->next;
	*stack = tmp;
	(*stack)->prev = NULL;
}
