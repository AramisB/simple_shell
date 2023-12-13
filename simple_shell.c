#include "simple_shell.h"

/**
 * main- a function that returns 0
 *
 * Return:0
 */
int main(void)
{
	char cmd[128];
	char *args[MAX_ARGS];
	int arg_count;

	while (1)
	{
		prompt_display();
		usr_input(cmd, sizeof(cmd));

		arg_count = tokenize(cmd, args);

		if (arg_count > 0)
		{
			execute_cmd(args);
			execute_cmd2(args[0], args);
		}

	}
	return (0);
}
