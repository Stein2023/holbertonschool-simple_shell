#include"main.h"

/**
 * pathchecksource - Function name
 * @env: environ
 * Return: String path
 */

char *pathchecksource(char **env)
{
	char *path = NULL;

	while (*env)
	{
		if (strncmp(*env, "PATH=", 5) == 0)
		{
			path = strdup(*env + 5);
			break;
		}
		env++;
	}
	if  (path == NULL)
		perror("Global Variable PATH not found in environ");
	return (path);
}
