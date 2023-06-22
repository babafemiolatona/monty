#ifndef _MONTY_H_
#define _MONTY_H_

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

extern int value;

extern int info;

/**
 * struct cmd_s - cmd
 * @f: file desc
 * @inputLine: line
 */

typedef struct cmd_s
{
	FILE *f;
	char *inputLine;
} cmd_t;

extern cmd_t cmd;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
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

void pop(stack_t **stackPtr, unsigned int line_num);
void push(stack_t **stackPtr, unsigned int line_num);
void pall(stack_t **stackPtr, unsigned int line_num);
void nop(stack_t **stackPtr, unsigned int line_num);
void pint(stack_t **stackPtr, unsigned int line_num);
void add(stack_t **stackPtr, unsigned int line_num);
void sub(stack_t **stackPtr, unsigned int line_num);
int ret_opcode(stack_t **stack, char *ret, char *val, int line_number);
int isDigit(char *ret);
void exec(char *argv);
stack_t *alloc_node(int n);
void push_err(FILE *f, char *inputLine, stack_t *stackPtr, int line_num);
void instruct_err(FILE *f, char *inputLine, stack_t *stackPtr,
char *val, int line_num);
void swap(stack_t **stackPtr, unsigned int line_num);
void _free(stack_t *stackPtr);
void argument_error(void);
void fileAccessError(char *file);

#endif
