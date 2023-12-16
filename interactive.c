#include "main.h"
/**
 * interactive - Function to run the interactive shell.
 * Return:
 */
void interactive(void)
{
	char *line = NULL, **array = NULL;
	int ntokens = 0;
	size_t line_size = 0;
	ssize_t read;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");
		read_line(&line, &line_size, &read);
		if (iswhite(line))
			continue;
		array = malloc(sizeof(char *) * (ntokens + 1));
		if (array == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		ntokens = tokenize_line(line, array);
		execom(array[0], array, environ);
		freedom(array, ntokens);
		free(line);
		line = NULL;
	}
}
