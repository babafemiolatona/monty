#include "monty.h"

/**
 * argument_error - prints an argument error message
 * Return: 0(Failure)
 */

void argument_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * fileAccessError - prints a file error message
 * @file: file name
 * Return: 0(Failure)
 */

void fileAccessError(char *file)
{
	fprintf(stderr, "Error: Can't open file %s\n", file);
	exit(EXIT_FAILURE);
}

/**
 * push_err - handles an error during a push
 * operation
 * @f: file descriptor associated with the operation
 * @inputLine: buffer containing the data being processed
 * @stackPtr: stack or queue where the push operation was attempted
 * @line_num: line number of the command being executed
 */

void push_err(FILE *f, char *inputLine, stack_t *stackPtr, int line_num)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_num);
	fclose(f);
	free(inputLine);
	_free(stackPtr);
	exit(EXIT_FAILURE);
}

/**
 * instruct_err - Error handler for unknown instructions
 * @f: file descriptor associated with the operation
 * @inputLine: buffer containing the data being processed
 * @stackPtr: stack or queue where the instruction was encountered
 * @line_num: line number of the command being executed
 * @val: unknown instruction encountered
 */

void instruct_err(FILE *f, char *inputLine, stack_t *stackPtr,
char *val, int line_num)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line_num, val);
	fclose(f);
	free(inputLine);
	_free(stackPtr);
	exit(EXIT_FAILURE);
}
