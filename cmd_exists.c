#include "simple_shell.h"

/**
 * cmd_exists - checks if the command exists in PATH
 * @cmd: command
 *
 * Return: 0 - if command doesn't exist
 */

int cmd_exists(char *cmd)
{
	char *path = _getenv("PATH");
	char *token;
	char *path_cpy;

	if (!path)
	{
		return (0);
	}

	path_cpy = strdup(path);

	token = strtok(path_cpy, ":");

	while (token != NULL)
	{
		char whole_path[MAX_INPUT_LEN];

		strcpy(whole_path, token);
		strcat(whole_path, "/");
		strcat(whole_path, cmd);

		if (access(whole_path, F_OK) != -1)
		{
			free(path_cpy);
			return (1);
		}

		token = strtok(NULL, ":");
	}

	free(path_cpy);
	return (0);
}
