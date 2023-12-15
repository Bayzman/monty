#include "monty.h"

/**
 * i_add - adds the top number and the next number in stacked dll
 * @head: head of am stack dll
 * @counter: counter
 */

void i_add(stack_t **head, unsigned int counter)
{
	stack_t *tmp;
	int len;
	int sum;

	tmp = *head;

	for (len = 0; tmp != NULL; len++)
		tmp = tmp->next;
	if (head == NULL || (*head)->next == NULL || len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short", counter);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	sum = (*head)->next->n + (*head)->n;
	i_pop(head, counter);
	(*head)->n = sum;

}
