#include "monty.h"

/**
 * mul - multiplies the second top element of the stack with
 * the top element of the stack.
 * @stackPtr: double pointer to top of the stack
 * @line_num: current line number
 */

void mul(stack_t **stackPtr, unsigned int line_num)
{
	stack_t *vand = NULL;
	int prd = 0;

	if (!*stackPtr || !(*stackPtr)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	vand = (*stackPtr)->next;
	prd = vand->n;
	prd *= (*stackPtr)->n;
	pop(stackPtr, line_num);
	vand->n = prd;
}

/**
 * mod - computes the rest of the division of the second top
 * element of the stack by the top element of the stack
 * @stackPtr: Pointer to top of the stack.
 * @line_num: current line number
 */

void mod(stack_t **stackPtr, unsigned int line_num)
{
	int res;

	if (stackPtr == NULL || *stackPtr == NULL || (*stackPtr)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	if ((*stackPtr)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_num);
		exit(EXIT_FAILURE);
	}
	(*stackPtr) = (*stackPtr)->next;
	res = (*stackPtr)->n % (*stackPtr)->prev->n;
	(*stackPtr)->n = res;
	free((*stackPtr)->prev);
	(*stackPtr)->prev = NULL;
}
