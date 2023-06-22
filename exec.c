#include "monty.h"

cmd_t cmd = {NULL, NULL};

/**
 * exec - parses the file and executes the monty byte
 * @args_arr: arguments array
 */

void exec(char *args_arr)
{
	int c_line = 0, r = 0;
	size_t bufsize = 0;
	char *lxm = NULL, *val = NULL;
	stack_t *stackPtr = NULL;

	cmd.f = fopen(args_arr, "r");
	if (cmd.f)
	{
		while (getline(&cmd.inputLine, &bufsize, cmd.f) != -1)
		{
			c_line++;
			lxm = strtok(cmd.inputLine, " \n\t\r");
			if (lxm == NULL)
			{
				free(lxm);
				continue;
			}
			else if (*lxm == '#')
				continue;
			val = strtok(NULL, " \n\t\r");
			r = ret_opcode(&stackPtr, lxm, val, c_line);
			if (r == 1)
				push_err(cmd.f, cmd.inputLine, stackPtr, c_line);
			else if (r == -1)
				instruct_err(cmd.f, cmd.inputLine, stackPtr, lxm, c_line);
		}
		free(cmd.inputLine);
		_free(stackPtr);
		fclose(cmd.f);
	}
	else
	{
		fileAccessError(args_arr);
	}
}
