#include "simple_shell.h"
/**
 * print_func - a function that prints custom shell
 * @msg: pointer to a string
 */
void print_func(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	vfprintf(stdout, format, args);
	va_end(args);
}
