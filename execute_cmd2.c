#include "simple_shell.h"

/**
 * execute_cmd2- forks a child process and exxecute
 * given command
 *
 * @cmd: command
 * @tokens: parameter
 */

void execute_cmd2(char *cmd, char **tokens)
{
	pid_t childPID = fork();

	if (childPID == -1)
	{
		handle_error("error");
		exit(EXIT_FAILURE);
	}
	else if (childPID == 0)
	{
		execve(cmd, tokens, NULL);

		handle_error("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
