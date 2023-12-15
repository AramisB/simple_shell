#include "simple_shell.h"

/**
 * cmd_exists - checks if the command exists in PATH
 * @cmd: command
 *
 *Return:  full_path when command exists and NULL if it doesn't exist
 */

char *cmd_exists(char *cmd)
{
	char *path = _getenv("PATH");
	char *token;
	char *path_cpy;
	char *full_path = NULL;

	if (strchr(cmd, '/') != NULL)
	{
		return (strdup(cmd));
	}

	if (!path)
	{
		return (NULL);
	}

	path_cpy = strdup(path);

	token = strtok(path_cpy, ":");

	while (token != NULL)
	{
		struct stat cmd_info;
		char whole_path[MAX_INPUT_LEN];

		strcpy(whole_path, token);
		strcat(whole_path, "/");
		strcat(whole_path, cmd);

		if (stat(whole_path, &cmd_info) == 0)
		{
			full_path = strdup(whole_path);
			break;
		}

		token = strtok(NULL, ":");
	}

	free(path_cpy);

	if (full_path != NULL)
	{
		return (full_path);
	}
	free(full_path);
	return (NULL);
}
