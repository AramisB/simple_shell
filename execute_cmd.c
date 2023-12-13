#include "simple_shell.h"

/**
 * execute_cmd- a function to execute commands/prompts
 * @args: array of arguments
 */

void execute_cmd(char *args[])
{
	if (strcmp(args[0], "exit") == 0)
	{
		execute_exit();
	}
	else if (strcmp(args[0], "env") == 0)
	{
		implement_env();
		return;
	}

	if (!cmd_exists(args[0]))
	{
		print_func("Command not found: %s\n", args[0]);
	}
	else
	{
		execute_cmd2(args[0], args);
	}
}
