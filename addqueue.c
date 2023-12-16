#include "monty.h"

/**
 * addqueue - adds a queue to the dll
 * @head: head of the node
 * @n: int
 */

void addqueue(stack_t **head, int n)
{
	stack_t *new_node, *tmp;

	tmp = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		printf("Error\n");
	new_node->n = n;
	new_node->next = NULL;

	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
	}
	if (!tmp)
	{
		(*head) = new_node;
		new_node->prev = NULL;
	}
	else
	{
		tmp->next = new_node;
		new_node->prev = tmp;
	}

}
