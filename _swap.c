#include "monty.h"

/**
 * _swap - swap 2 top elements
 *@stack: stack pointer
 *@line_number: line number
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;
	int trade1 = 0, trade2 = 0;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	trade1 = (*stack)->n;
	aux = (*stack)->next;
	trade2 = aux->n;
	(*stack)->n = trade2;
	aux->n = trade1;
}
