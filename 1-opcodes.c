#include "monty.h"

/**
 * pop - Removes the top element of the stack
 * @stackPtr: pointer to head of stack
 * @line_num: line number
 */

void pop(stack_t **stackPtr, unsigned int line_num)
{
	stack_t *tmpVar;

	if (*stackPtr == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}

	tmpVar = *stackPtr;
	*stackPtr = tmpVar->next;
	if (*stackPtr != NULL)
	{
		(*stackPtr)->prev = NULL;
	}
	free(tmpVar);
}


/**
 * swap - swaps the two elements of the stack.
 * @stackPtr: double pointer to the top of the list
 * @line_num: current line number
 */

void swap(stack_t **stackPtr, unsigned int line_num)
{
	stack_t *hat = *stackPtr, *addr;

	if ((*stackPtr) == NULL || (*stackPtr)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	if (hat && hat->next)
	{
		addr = hat->next;
		if (addr->next)
			addr->next->prev = hat;
		hat->next = addr->next;
		addr->prev = NULL;
		addr->next = hat;
		hat->prev = addr;
		*stackPtr = addr;
	}
}

/**
 * add - adds the top two elements of the stack.
 * @stackPtr: pointer to top of the stack
 * @line_num: current line number
 */

void add(stack_t **stackPtr, unsigned int line_num)
{
	stack_t *heta = *stackPtr, *n;

	if ((*stackPtr) == NULL || (*stackPtr)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	if (*stackPtr && (*stackPtr)->next)
	{
		n = heta->next;
		n->n += heta->n;
		free(heta);
		*stackPtr = n;
	}
}

/**
 * sub - subtracts the top element of the stack from
 * the second top element of the stack
 * @stackPtr: double pointer to the top of the stack
 * @line_num: current line number
 */

void sub(stack_t **stackPtr, unsigned int line_num)
{
	stack_t *vet = NULL;
	int res = 0;

	if (*stackPtr == NULL || (*stackPtr)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	vet = (*stackPtr)->next;
	res = vet->n;
	res -= (*stackPtr)->n;
	pop(stackPtr, line_num);
	vet->n = res;
}
