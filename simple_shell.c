#include "simple_shell.h"

/**
 * main- a function that returns 0
 *
 * Return:0
 */
int main(void)
{
	char cmd[128];
	char cmd_line[256];

	while (1)
	{
		prompt_display();
		usr_input(cmd, sizeof(cmd));
		execute_cmd(cmd);
		execute1_cmd(cmd_line);
	}
	return (0);
}
