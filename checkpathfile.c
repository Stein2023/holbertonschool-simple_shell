#include"main.h"

/**
 * checkpathfile - Function Name
 * @pathline: path string
 * @command: command to execute
 * Return: returns a string
 */

char *checkpathfile(char *pathline, char *command)
{
	char *func = "checkpathfile";
	struct stat filestat;
	size_t len;
	char *trypath, *delimiters = ":", *fullpath;

	trypath = strtok(pathline, delimiters);
	while (trypath != NULL)
	{
		len = strlen(trypath) + strlen(command) + 2;
		fullpath = malloc(len);
		if (fullpath == NULL)
		{
			showerror("Error on Malloc");
		}
		sprintf(fullpath, "%s/%s", trypath, command);
		if (stat(fullpath, &filestat) == 0)
			return (fullpath);
		freestring(fullpath, func);
		trypath = strtok(NULL, delimiters);
	}
	return (NULL);
}
