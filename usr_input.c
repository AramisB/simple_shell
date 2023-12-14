#include "simple_shell.h"

/**
 * usr_input - Receives user input using getline.
 * @cmd: Double pointer to a string to store user input.
 *
 *
 */
void usr_input(char **cmd)
{
        size_t size = 0;
        ssize_t read_chars;

        read_chars = getline(cmd, &size, stdin);

        if (read_chars == -1)
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

        if ((*cmd)[read_chars - 1] == '\n')
        {
                (*cmd)[read_chars - 1] = '\0';
        }
}
