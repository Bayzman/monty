#include "monty.h"

/**
 * i_push - push data to the top of a stack
 * @head: the head of a stack double ll
 * @counter: line number
 * Return: void
 */

void i_push(stack_t **head, unsigned int counter)
{
	int n;
	int j;
	int flag;

	j = 0;
	flag = 0;

	if (buf.arg)
	{
		if (buf.arg[0] == '-')
			j++;
		for (; buf.arg[j] != '\0'; j++)
		{
			if (buf.arg[j] > 57 || buf.arg[j] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(buf.file);
			free(buf.command);
			free_dlist(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(buf.file);
		free(buf.command);
		free_dlist(*head);
		exit(EXIT_FAILURE);
	}
	n = atoi(buf.arg);
	if (buf.flag == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}
