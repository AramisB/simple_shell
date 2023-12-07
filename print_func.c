#include "simple_shell.h"
/**
 * print_func - a function that prints custom shell
 * @msg: pointer to a string
 */
void print_func(const char *msg)
{
	write(STDOUT_FILENO, msg, strlen(msg));
}
