#ifndef HEADER
#define HEADER
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

stack_t *addto(stack_t **head, const int n);
stack_t *add_nodeint(stack_t **head, const int n);
char **tokenizer(char *buffer, char *separator);
int identify(char **arr, stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
int _push(char **arr, stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void  _pop(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);
int init_stack(stack_t **stack);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);

void free_array(char **arr);
void free_stack(stack_t **head);

#endif
