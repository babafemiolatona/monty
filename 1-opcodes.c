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
