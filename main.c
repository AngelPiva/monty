#include "monty.h"

/**
 *
 */

void main(void)
{
	char *buffer = NULL;
	size_t size = 0;
	unsigned int n = 0;
	stack_t **stack;

	stack = malloc(sizeof(stack_t));

	while (getline(&buffer, &size, stdin) != -1)
	{
		identify(buffer, stack, n);
		n++;
		/*identify(buffer);*/
	}

}

/**
 * identify - identifies commands on the input string.
 *@input: input string.
*/ 

void identify(char *input, stack_t **stack, unsigned int line_number)
{
	int n = 0;
	char *compare = NULL;
	instruction_t identifiers[] = {
	{"push", _push},
	{"pall", _pall},
	{NULL, NULL}
	};

	while(identifiers[n].opcode != NULL)
	{
		compare = strstr(input, identifiers[n].opcode);
		if (compare != NULL)
		{
			if (strstr("push", input) != NULL)
			{

			}
			identifiers[n].f(stack, line_number);
			break;
		}
		n++;
	}
}
