#include"main.h"

/**
 * builtcheck - checks for built in commands
 * @command: command to execute
 * Return: void
 */

void builtcheck(char *command)
{
	if (strcmp(command, "exit") == 0)
		exit_builtin();
	if (strcmp(command, "env") == 0)
		handle_env();
}
