#include "monty.h"

/**
 *main - main function
 *Return: 1 on succes, -1 on failury
 */

int main(int argc, char *argv[])
{
	char *buffer = NULL;
	size_t size = 0;
	unsigned int line_number = 1;
	char **arr = NULL;
	stack_t **stack = NULL;
	FILE *_ofile = NULL;
	(void)argc;

	stack = malloc(sizeof(stack_t));
	if (!stack)
		return (-1);

	_ofile = fopen(argv[1], "r");
	if (!_ofile)
		return (-1);

	while (getline(&buffer, &size, _ofile) != -1)
	{
		arr = tokenizer(buffer, " \n\t");
		identify(arr, stack, line_number);
		line_number++;
	}

	return (1);
}

/**
 *identify - identifies commands on the input string.
 *@arr: buffer separated by tokens.
 *@stack: doubly linked list where integers are stored
 *@line_number: line number
*/

void identify(char **arr, stack_t **stack, unsigned int line_number)
{
	int n = 0;
	char *compare = NULL;
	instruction_t identifiers[] = {
	{"push", NULL},
	{"pall", _pall},
	{NULL, NULL}
	};

	while (identifiers[n].opcode != NULL)
	{
		compare = strstr(arr[0], identifiers[n].opcode);
		if (compare != NULL)
		{
			if (strstr("push", arr[0]) != NULL)
			{
				_push(arr, stack, line_number);
			}
			else
			{
				identifiers[n].f(stack, line_number);
			}
			break;
		}
		n++;
	}
}
