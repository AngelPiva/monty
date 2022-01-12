#include "monty.h"

/**
 *_pall - prints all elements from the stack
 *@stack: stack
 *@line_number: line number
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;
	(void)line_number;

	tmp = *stack;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
