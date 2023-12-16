#include "main.h"
/**
 * main - entry point
 * Return: 0
 */
int main(void)
{
	if (isatty(STDIN_FILENO))
	{
		interactive();
	}
	else
	{
		nonInteractive();
	}
	return (0);
}
