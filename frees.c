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
 *free_dlistint - frees a dlistint_t list
 *@head: head
 */

void free_dlistint(stack_t **head)
{
	stack_t *x = NULL;

	while (*head)
	{
		x = *head;
		free(x->prev);
		*head = (*head)->next;
		free(x);
	}
	free(*head);
	*head = NULL;
}
