#ifndef SIMPLE_SHEL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void prompt_display(void);
void print_func(const char *msg);
void usr_inpu(char *cmd, size_t size);
void execute_cmd(const char *cmd);

#endif

