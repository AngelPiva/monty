#include "monty.h"

/**
 * _div - divides top 2 elements of stack
 *@stack: stack ptr
 *@line_number: line number
 */

void _div(stack_t **stack, unsigned int line_number)
{
	int num1 = 0, num2 = 0;
	stack_t *aux;

	if (num1 == 0)
	{
		fprintf(stderr, "L<%d>: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (!*stack || (*stack)->next)
	{
		fprintf(stderr, "L<%d>: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	num1 = (*stack)->n;
	num2 = (*stack)->next->n;
	aux = (*stack)->next;
	aux->prev = NULL;
	*stack = aux;
	(*stack)->n = num2 / num1;
}
