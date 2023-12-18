#include "main.h"
/**
 * interactive - Function to run the interactive shell.
 * Return:
 */
void interactive(void)
{
	char *func = "interactive";
	char *line, **array;
	int ntokens = 0;
	size_t line_size = 0;
	ssize_t read;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");
		read_line(&line, &line_size, &read);
		if (iswhite(line))
		{
			freestring(line,func);
			continue;
		}
		array = malloc(sizeof(char *) * (ntokens + 2));
		if (array == NULL)
		{	
			freestring(line, func);
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		ntokens = tokenize_line(line, array);
		execom(array[0], array);
		freedom(array, func);
	}
}

