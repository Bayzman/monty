#ifndef MONTY
#define MONTY
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct buf_obj - buffer object
 * @arg: parsed args
 * @file: monty file pointer
 * @command: line commands
 * @flag: arg flag
 * Description: parameters objects
 */

typedef struct buf_obj
{
	char *arg;
	FILE *file;
	char *command;
	int flag;
}  buf_obj;
extern buf_obj buf;
typedef char *string;

/*DLL Functions*/
void free_dlist(stack_t *head);
void addnode(stack_t **head, int n);
void addqueue(stack_t **head, int n);

/*Opcodes execute functon*/
int exec_op(string command, stack_t **head, unsigned int count, FILE *file);

/*Stack operation functions*/
void i_push(stack_t **head, unsigned int counter);
void i_pall(stack_t **head, unsigned int counter);
void i_pint(stack_t **head, unsigned int counter);
void i_pop(stack_t **head, unsigned int counter);
void i_swap(stack_t **head, unsigned int counter);
void i_add(stack_t **head, unsigned int counter);
void i_nop(stack_t **head, unsigned int counter);
void i_sub(stack_t **head, unsigned int counter);
void i_div(stack_t **head, unsigned int counter);
void i_mul(stack_t **head, unsigned int counter);
void i_mod(stack_t **head, unsigned int counter);
void i_pchar(stack_t **head, unsigned int counter);
void i_pstr(stack_t **head, unsigned int counter);
void i_rotl(stack_t **head, unsigned int counter);
void i_rotr(stack_t **head, unsigned int counter);
void i_stack(stack_t **head, unsigned int counter);
void i_queue(stack_t **head, unsigned int counter);

#endif
