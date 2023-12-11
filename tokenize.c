#include "simple_shell.h"
/**
 * tokenize - Function to tokenize input into arguments
 * @input: User input string
 * @args: Array to store arguments
 *
 * Return: Number of arguments
 */
int tokenize(char *input, char *args[])
{
	int arg_count = 0;
	char *token = strtok(input, " \t\n");

	while (token != NULL && arg_count < MAX_ARGS - 1)
	{
		args[arg_count++] = token;
		token = strtok(NULL, " \t\n");
	}
	args[arg_count] = NULL;

	return (arg_count);
}
