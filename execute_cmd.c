#include "simple_shell.h"

/**
 * execute_cmd- a function to execute commands/prompts
 * @cmd: character
 */

void execute_cmd(const char *cmd)
{
	pid_t childPID;

	childPID = fork();

	if (childPID == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	else if (childPID == 0)
	{
		char *argv[2];

		argv[0] = (char *)cmd;
		argv[1] = NULL;

		execve(cmd, argv, NULL);

		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}

