#include "simple_shell.h"

/**
 * execute_cmd- a function to execute commands/prompts
 * @args: array of arguments
 */

void execute_cmd(char *args[])
{
i	pid_t childPID;

	childPID = fork();

	if (childPID == -1)
	{
		handle_error("fork");
		exit(EXIT_FAILURE);
	}
	else if (childPID == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			handle_error("execve");
		}
		_exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
