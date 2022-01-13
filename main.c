#include "monty.h"

/**
 *main - main function
 *@argc: arguments count
 *@argv: arguments value
 *Return: 1 on succes, -1 on failury
 */

int main(int argc, char *argv[])
{
	char *buffer = NULL;
	size_t size = 0;
	unsigned int line_number = 1;
	int status = 0;
	char **arr = NULL;
	stack_t **stack = NULL;
	FILE *_ofile = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	}
	stack = malloc(sizeof(stack_t));
	if (!stack)
	{
		fprintf(stderr, "Error: malloc failed"), exit(EXIT_FAILURE);
	}
	_ofile = fopen(argv[1], "r");
	if (!_ofile)
	{
		fprintf(stderr, "Can't open file <%s>\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&buffer, &size, _ofile) != -1)
	{
		arr = tokenizer(buffer, " \n\t");
		status = identify(arr, stack, line_number);
		if (status == -1)
		{
			free(arr), free_stack(stack), free(buffer), fclose(_ofile);
			exit(EXIT_FAILURE);
		}
		line_number++;
		free(arr);
	}
	free(buffer), free_stack(stack), fclose(_ofile);
	return (0);
}
/**
 *identify - identifies commands on the input string.
 *@arr: buffer separated by tokens.
 *@stack: doubly linked list where integers are stored
 *@line_number: line number
 *Return: 0 in success, -1 in failure
*/

int identify(char **arr, stack_t **stack, unsigned int line_number)
{
	int n = 0, status = 0;
	char *compare = NULL;
	instruction_t identifiers[] = {
	{"push", NULL},
	{"pall", _pall},
	{"pint", _pint},
	{"pop", _pop},
	{"nop", _nop},
	/*
	*{"swap", _swap},
	*{"add", _add},
	*/
	{NULL, NULL}
	};

	while (identifiers[n].opcode != NULL)
	{
		compare = strstr(arr[0], identifiers[n].opcode);
		if (compare != NULL)
		{
			if (strstr("push", arr[0]) != NULL)
			{
				status = _push(arr, stack, line_number);
				if (status == -1)
					return (-1);
			}
			else
			{
				identifiers[n].f(stack, line_number);
			}
			break;
		}
		n++;
	}
	if (compare == NULL)
	{
		fprintf(stderr, "L<%d>: unknown instruction <%s>\n", line_number, arr[0]);
		return (-1);
	}
	return (0);
}
