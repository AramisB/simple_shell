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
	int status;

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
		waitpid(childPID, &status, 0);

		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		{
			print_func("Command execution failed: %s\n", cmd);
		}
	}
}
