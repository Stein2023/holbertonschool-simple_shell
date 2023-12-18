#include "main.h"
/**
 * nonInteractive - function to run in non-interactive mode, executes a series
 * of commands that are passed as arguments.
 * Return:
 */
void nonInteractive(void)
{
	char *func = "noninteractive";
	char *line = NULL;
	char **array = NULL;
	int ntokens = 0;
	ssize_t read;
	size_t line_size = 0;

	while (1)
	{
		read_line(&line, &line_size, &read);
		if (iswhite(line))
		{
			freestring(line, func);
			exit(EXIT_SUCCESS);
		}
		array = malloc(sizeof(char *) * (ntokens + 2));
		if (array == NULL)
		{	
			freestring(line, func);
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		ntokens = tokenize_line(line, array);
		execom(array[0], array, environ);
		freedom(array, func);
	}
}
