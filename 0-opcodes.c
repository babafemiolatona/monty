#include "monty.h"

int value;

/**
 * alloc_node - allocates memory for a new node and
 * initializes it with the given value
 * @n: value to be assigned to the new node
 * Return: pointer to the newly created node
*/

stack_t *alloc_node(int n)
{
	stack_t *new_node = NULL;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

/**
 * push - adds a new node with the specified value to the stack
 * @stackPtr: double pointer to the head of the stack
 * @line_num: value to be pushed onto the stack
 */

void push(stack_t **stackPtr, unsigned int line_num)
{
	stack_t *new_node = NULL;

	(void)line_num;

	new_node = alloc_node(value);

	new_node->next = *stackPtr;
	if (*stackPtr != NULL)
	{
		(*stackPtr)->prev = new_node;
	}
	*stackPtr = new_node;
}

/**
 * pall - prints all the values on the stack
 * @stackPtr: double pointer to the head of the stack
 * @line_num: current line number
 */

void pall(stack_t **stackPtr, unsigned int line_num)
{
	stack_t *tmpVar = NULL;
	(void)line_num;

	tmpVar = *stackPtr;

	while (tmpVar != NULL)
	{
		fprintf(stdout, "%d\n", tmpVar->n);
		tmpVar = tmpVar->next;
	}
}

/**
 * pint - prints value at the head of the stack
 * @stackPtr: pointer to head of the stack
 * @line_num: current line number
 */

void pint(stack_t **stackPtr, unsigned int line_num)
{
	if (*stackPtr == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%d\n", (*stackPtr)->n);
}
