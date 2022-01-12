#include "monty.h"

/**
 *add_dnodeint - adds a new node at the beginning of a dlistint_t list.
 *@head: head
 *@n: number at the new node
 *Return: the address of the new element, or NULL if it failed
 */

stack_t *add_nodeint(stack_t **head, const int n)
{
	stack_t *new = NULL;

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
		new->next = *head;
		new->prev = (*head)->prev;
		(*head)->prev = new;
		*head = new;
		return (*head);
	}
	return (NULL);
}
