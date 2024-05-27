#include "simple_shell.h"

/**
 * execute_cmd - a function to execute commands/prompts
 * @args: array of arguments
 */
void execute_cmd(char *args[])
{
	char *full_path;
	char *envp[] = {
		"VAR1=value1",
		"VAR2=value2",
		NULL};
	if (strcmp(args[0], "exit") == 0)
	{
		execute_exit();
	}
	else if (strcmp(args[0], "env") == 0)
	{
		implement_env();
		return;
	}

	full_path = cmd_exists(args[0]);
	if (!full_path)
	{
		print_func("Command not found: %s\n", args[0]);
	}
	else
	{
		execute_cmd2(full_path, args, envp);
		free(full_path);
	}
}

/**
 * execute_cmd2 - function that forks child process
 * and executes given command
 * @cmd: parameter to be executed
 * @tokens: a string array
 * @envp: an array of strings representing the environment variables
 */
void execute_cmd2(char *cmd, char **tokens, char **envp)
{
	pid_t childPID = fork();
	int status;

	if (childPID == -1)
	{
		handle_error("error");
	}
	else if (childPID == 0)
	{
		execve(cmd, tokens, envp);
		handle_error("execve");
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
