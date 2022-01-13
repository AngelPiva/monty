#include "monty.h"
/**
 * _pchar - prints the corresponding alpha to the ascii
 *@stack: stack ptr
 *@line_number: line number
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	if(!*stack)
	{
		fprintf(stderr, "L<%d>: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (((*stack)->n < 65 || (*stack)->n > 90) && ((*stack)->n < 97 || (*stack)->n > 122))
	{
		fprintf(stderr, "L<%d>: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	putchar((*stack)->n);
	putchar(10);
}
