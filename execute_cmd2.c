#include "simple_shell.h"

/**
 * execute_cmd2- function that forks child process
 * and executes given command
 * @cmd: parameter to be executed
 * @tokens: a string array
 *
 *
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

		perror("execve");
		_exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
