#include "monty.h"

/**
 *free_array - frees an array of strings
 *@arr: array of strings
 */

void free_array(char **arr)
{
	int n = 0;

	while (arr[n])
	{
		free(arr[n]);
		n++;
	}
	free(arr);
}

/**
 *free_stack - frees a dlistint_t list
 *@head: head
 */

void free_stack(stack_t **head)
{
	stack_t *x = NULL;

	while (*head)
	{
		x = *head;
		*head = (*head)->next;
		free(x);
	}
	free(*head);
	*head = NULL;
}
