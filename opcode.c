#include "monty.h"

/**
* exec_op - execute the opcode
* @head: head linked list - stack
* @count: line_counter
* @file: pointer to monty file
* @command: line content
* Return: int
*/

int exec_op(string command, stack_t **head, unsigned int count, FILE *file)
{
	string delim = " \n\t";
	unsigned int i = 0;
	string c_op;

	/*Declaring the opcodes struct*/
	instruction_t opt[] = {
		{"push", i_push},
		{"pall", i_pall},
		{"pint", i_pint},
		{"pop", i_pop},
		{"swap", i_swap},
		{"add", i_add},
		{"nop", i_nop},
		{NULL, NULL}
	};

	/*Tokenzing the commands args to be executed */
	c_op = strtok(command, delim);
	if (c_op && c_op[0] == '#')
		return (0);
	buf.arg = strtok(NULL, delim);
	while (opt[i].opcode && c_op)
	{
		if (strcmp(c_op, opt[i].opcode) == 0)
		{
			opt[i].f(head, count);
			return (0);
		}
		i++;
	}
	if (c_op && !opt[i].opcode)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", count, c_op);
		fclose(file);
		free(command);
		free_dlist(*head);
		exit(EXIT_FAILURE);
	}
	return (1);


}
