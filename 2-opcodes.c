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
