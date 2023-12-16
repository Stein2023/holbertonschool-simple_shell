#include "main.h"
/**
 * handle_env - function to print all the environment variables.
 *
 * Return:
 */
void handle_env(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
}
