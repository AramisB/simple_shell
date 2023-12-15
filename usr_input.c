#include "simple_shell.h"

/**
 * usr_input - Receives user input using getline.
 * @cmd: Double pointer to a string to store user input.
 *
 * Return: user input as a string
 */
char *usr_input(char **cmd)
{
	char *line = NULL;
	size_t len = 0;
	size_t input_length;

	if (getline(&line, &len, stdin) == -1)
	{
		perror("getline");
		exit(EXIT_FAILURE);
	}
	input_length = strlen(line);

	if (input_length > 0 && line[input_length - 1] == '\n')
	{
		line[input_length - 1] = '\0';
	}
	*cmd = strdup(line);
	free(line);
	return (*cmd);
}
