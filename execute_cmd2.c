#include "simple_shell.h"

/**
 * execute_cmd2- function that forks child process
 * and executes given command
 * @cmd: parameter to be executed
 * @tokens: a string array
 * @envp: an array of strings representing the environment variables
 *
 */

void execute_cmd2(char *cmd, char **tokens, char **envp)
{
	pid_t childPID = fork();
	int status;
	char *full_path = NULL;

	if (childPID == -1)
	{
		handle_error("error");
	}
	else if (childPID == 0)
	{
		full_path = cmd_exists(cmd);

		if (full_path != NULL)
		{
			execve(full_path, tokens, envp);
			handle_error("execve");
		}
	}
	else
	{
		waitpid(childPID, &status, 0);

		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		{
			print_func("Command execution failed: %s\n", cmd);
		}
		if (full_path != NULL)
		{
			free(full_path);
		}
	}
}
