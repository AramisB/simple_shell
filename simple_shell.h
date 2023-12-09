#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void prompt_display(void);
void print_func(const char *msg);
void usr_input(char *cmd, size_t size);
void execute_cmd(const char *cmd);
void execute1_cmd(const char *cmd_line);

#endif

