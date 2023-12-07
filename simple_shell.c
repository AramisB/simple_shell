#include "simple_shell.h"

/**
 * main- a function that returns 0
 *
 * Return:0
 */
int main(void)
{
	char cmd[128];

	while (1)
	{
		prompt_display();
		usr_input(cmd, sizeof(cmd));
		execute_cmd(cmd);
	}
	return (0);
}
