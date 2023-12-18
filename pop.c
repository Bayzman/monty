#include "monty.h"

/**
 * i_pop - rempves the top element of dll
 * @head: head of dll
 * @counter: line number
 */

void i_pop(stack_t **head, unsigned int counter)
{
	stack_t *tmp;

	tmp = *head;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		exit(EXIT_FAILURE);
	}

	*head = tmp->next;
	if (*head)
		(*head)->prev = NULL;
	free(tmp);
}
