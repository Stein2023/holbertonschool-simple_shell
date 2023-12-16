#include "main.h"
/**
 * nonInteractive - function to run in non-interactive mode, executes a series
 * of commands that are passed as arguments.
 * Return:
 */
void nonInteractive(void)
{
	char *line = NULL;
	char **array = NULL;
	int ntokens = 0;
	size_t line_size = 0;
	ssize_t read;

	while (1)
	{
		read_line(&line, &line_size, &read);
		if (iswhite(line))
			exit(EXIT_SUCCESS);
		array = malloc(sizeof(char *) * (ntokens + 1));
		if (array == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		ntokens = tokenize_line(line, array);
		execom(array[0], array, environ);
		free(array);
	}
}
