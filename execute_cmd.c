#include "simple_shell.h"

/**
 * execute_cmd- a function to execute commands/prompts
 * @cmd: character
 */

void execute_cmd(const char *cmd)
{
	pid_t childPID;
	const char **args = malloc(2 * sizeof(char *));

	childPID = fork();

	if (childPID == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	else if (childPID == 0)
	{
		if (args == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
			execve(cmd, (char *const *)args, (char *const *)NULL);
			exit(EXIT_FAILURE);
			free(args);
		}
	}
	else
	{
		wait(NULL);
	}
}
