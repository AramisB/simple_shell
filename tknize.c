#include "simple_shell.h"

/**
 * tknize- function that takes input
 * @input: parameter
 * @args: parameter
 * @arg_count: parameter
 *
 */

void tknize(char *input, char **args, int *arg_count)
{
	char *token = strtok(input, " \t\n");
	*arg_count = 0;

	while (token != NULL && *arg_count < MAX_ARGS)
	{
		args[(*arg_count)++] = token;
		token = strtok(NULL, " \t\n");
	}
}
