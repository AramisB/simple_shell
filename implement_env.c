#include "simple_shell.h"
/**
 * implement_env - a function to implement the env built-in command
 */
void implement_env(void)
{
	char **environ_copy = environ;
	int i;

	for (i = 0; environ_copy[i] != NULL; i++)
	{
		write(STDOUT_FILENO, environ_copy[i], strlen_copy(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
}
