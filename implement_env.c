#include "simple_shell.h"
/**
 * implement_env - a function to implement the env built-in command
 */
void implement_env(void)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
}
