#include"main.h"
/**
 * showerror - shows an error and exits
 * @string: frist parameter
 * Return: void
 */
void showerror(char *string)
{
	perror(string);
	exit(EXIT_FAILURE);
}
