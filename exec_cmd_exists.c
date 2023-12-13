#include "simple_shell.h"

/**
 * exec_cmd_exists- function that executes cmd_exists
 *
 */

void exec_cmd_exists(void)
{
	char input[MAX_INPUT_LEN];
	char *args[MAX_ARGS];
	int arg_count = 0;

	while (1)
	{
		print_func("Custom_Shell$$ ");

		if (fgets(input, MAX_INPUT_LEN, stdin) == NULL)
		{
			break;
		}

		input[strcspn(input, "\n")] = '\0';

		tknize(input, args, &arg_count);

		if (arg_count > 0)
		{
			char *cmd = args[0];

			if (cmd_exists(cmd))
			{
				execute_cmd2(cmd, args);
			}
			else
			{
				print_func("Command not found: %s\n");
			}
		}
		memset(args, 0, sizeof(args));
	}
}
