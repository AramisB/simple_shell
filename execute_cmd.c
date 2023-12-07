#include "simple_shell.h"

/**
 * execute_cmd- a function to execute commands/prompts
 * @cmd: character
 */

void execute_cmd(const char *cmd)
{
	pid_t childPID = fork();

	if (childPID == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	else if (childPID == 0)
	{
		execve(cmd, cmd, (char *)NULL);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
