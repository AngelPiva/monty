#include "monty.h"

/**
 *_pstr -  prints the string starting at the top of the stack
 *@stack: stack
 *@line_number: line number
 */

void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;
	(void)line_number;

	while (aux)
	{
		if (aux->n <= 0 || aux->n > 127)
			break;
		putchar(aux->n);
		aux = aux->next;
	}
	putchar(10);
}
