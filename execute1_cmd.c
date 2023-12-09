#include "simple_shell.h"

/**
 * execute1_cmd - a function to execute commands with arguments
 * @cmd_line: command line containing the command and its arguments
 */
void execute1_cmd(const char *cmd_line)
{
    pid_t childPID;

    char *token;
    char *args[64];
    int arg_count = 0;

    token = strtok((char *)cmd_line, " \t\n");
    while (token != NULL)
    {
        args[arg_count++] = token;
        token = strtok(NULL, " \t\n");
    }
    args[arg_count] = NULL;

    childPID = fork();

    if (childPID == -1)
    {
        perror("Error");
        exit(EXIT_FAILURE);
    }
    else if (childPID == 0)
    {
        execve(args[0], args, NULL);

        perror("execve");
        exit(EXIT_FAILURE);
    }
    else
    {
        wait(NULL);
    }
}
