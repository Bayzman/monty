#include "monty.h"

/**
 * i_swap - swap the top and the next data
 * @head: head of the dll
 * @counter: counter (line number)
 */

void i_swap(stack_t **head, unsigned int counter)
{
	stack_t *tmp;
	int num;

	tmp = *head;
	if (tmp == NULL || tmp->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		exit(EXIT_FAILURE);
	}
	num = tmp->n;
	tmp->n = tmp->next->n;
	tmp->next->n = num;

}
