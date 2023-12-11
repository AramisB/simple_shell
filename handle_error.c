#include "simple_shell.h"
#include <errno.h>

/**
 * handle_error - a function to handle errors and print error messages
 * @msg: error message to print
 */
void handle_error(const char *msg)
{
	if (errno != 0)
	{
		perror(msg);
	}
	exit(EXIT_FAILURE);
}
