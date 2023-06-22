#include "monty.h"

/**
 * ret_opcode - gets the opcode function
 * @stack: pointer to the stack or queue
 * @ret: command for which to retrieve the opcode function
 * @val: value associated with the command
 * @line_number: line number where the command appears
 * Return: 0 on success, 1 if the value is not a digit, or -1 on error
 */

int ret_opcode(stack_t **stack, char *ret, char *val, int line_number)
{
	int i = 0;

	instruction_t op[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"nop", nop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{NULL, NULL}
	};

	while (op[i].opcode)
	{
		if (!strcmp(ret, op[i].opcode))
		{
			if (!strcmp(ret, "push"))
			{
				if (isDigit(val) == 1)
				{
					value = atoi(val);
				}
				else
				{
					return (1);
				}
			}
			op[i].f(stack, (unsigned int)line_number);
			break;
		}
		i++;
	}
	if (!op[i].opcode)
	{
		return (-1);
	}
	return (0);
}

/**
 * isDigit - checks if it is a digit
 * @ret: Value
 * Return: 0 or 1(Success or Failure)
 **/

int isDigit(char *ret)
{
	char *tmpVar = ret;

	if (ret == NULL)
	{
		return (0);
	}
	if (*tmpVar == '-')
	{
		tmpVar++;
	}

	for (; *tmpVar != '\0'; tmpVar++)
	{
		if ((*tmpVar < '0' || *tmpVar > '9'))
		{
			return (0);
		}
	}
	return (1);
}

