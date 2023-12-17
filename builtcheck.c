#include"main.h"

/**
 *  * builtcheck - checks for built in commands
 *   * @command: command to execute
 *    * Return: void
 *     */

void builtcheck(char *command)
{
	char *func = "built check";
	if (strcmp(command, "exit") == 0)
	{	freestring(command, func);
		printf("EXIT FROM BUILT CHECK\n");
		exit_builtin();
	}
	if (strcmp(command, "env") == 0)
	{
		freestring(command, func);
		handle_env();
	}
}
