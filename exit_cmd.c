#include "simple_shell.h"

/**
 * execute_exit - a function that executes the built-in exit command.
 *
 */

void execute_exit(void)
{
	printf("Exiting the shell.\n");
	exit(EXIT_SUCCESS);
}
