#include "simple_shell.h"

/**
 * _getenv - retrieves the value of an environment variable
 * @variable: name of the environment variable
 *
 * Return: value of the environment variable or NULL if not found
 */
char *_getenv(const char *variable)
{
	int i;
	size_t variable_len;

	variable_len = strlen(variable);

	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], variable, variable_len) == 0 && environ[i][variable_len] == '=')
		{
			return environ[i] + variable_len + 1;
		}
	}
	return (NULL);
}
