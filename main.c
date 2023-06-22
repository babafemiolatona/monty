#include "monty.h"

/**
 * main - entry point of the program
 * @argc: number of command-line arguments passed to the program
 * @argv: array of strings containing the command-line arguments
 * Return: status of the program execution indicating
 * success or failure
 */

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		exec(argv[1]);
	}
	return (EXIT_SUCCESS);
}

#include "monty.h"

/**
 * _free - frees stack
 * @stackPtr: stack
 */

void _free(stack_t *stackPtr)
{
stack_t *list = NULL;

	list = stackPtr;

	if (list != NULL)
	{
		_free(list->next);
		free(list);
	}
}
