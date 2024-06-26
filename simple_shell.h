#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#define MAX_ARGS 64
#define MAX_INPUT_LEN 1024
extern char **environ;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdarg.h>
#include <sys/stat.h>
#include<errno.h>

void prompt_display(void);
void print_func(const char *format, ...);
char *usr_input(char **cmd);
void execute_cmd(char *args[]);
int tokenize(char *input, char *args[]);
void handle_error(const char *msg);
char *cmd_exists(char *cmd);
void execute_exit(void);
void execute_cmd2(char *cmd, char **tokens, char **envp);
void implement_env(void);
void tknize(char *input, char **args, int *arg_count);
char *_getenv(const char *name);

#endif
