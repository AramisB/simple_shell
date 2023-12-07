#include "simple_shell.h"
/**
 * usr_input - a function that receives user input
 * @size: size of string
 * @cmd: pointer to a string
 *
 */
void usr_input(char *cmd, size_t size)
{
	if (fgets(cmd, size, stdin) == NULL)
	{
		if (feof(stdin))
		{
			print_func("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			print_func("Error while reading user input.");
			exit(EXIT_FAILURE);
		}
	}
	cmd[strcspn(cmd, "\n")] = "\0";
}
