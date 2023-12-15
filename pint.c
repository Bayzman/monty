#include "monty.h"

/**
 * i_pint - prints the top element of a stacked dll
 * @head: head of dll
 * @counter: counter
 */

void i_pint(stack_t **head, unsigned int counter)
{
	stack_t *tmp;

	tmp = *head;

	if (tmp == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", counter);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", tmp->n);
}
