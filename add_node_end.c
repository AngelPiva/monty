#include "monty.h"

/**
 *add_dnodeint_end - adds a new node at the end of a dlistint_t list.
 *@head: head
 *@n: number
 *Return: the address of the new element, or NULL if it failed
 */

stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *new = NULL, *tmp = NULL;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);
	new->n = n;

	if (*head == NULL)
	{
		new->next = *head;
		new->prev = NULL;
		*head = new;
		return (*head);
	}
	else
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		new->prev = tmp;
		new->next = NULL;
		tmp->next = new;
		return (new);
	}
	return (NULL);
}
