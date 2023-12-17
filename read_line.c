#include "main.h"
/**
 * read_line - reads a line of text from the standard input stream and stores
 * it in the memory location pointed to by line.
 * @line: a pointer to a pointer to a character. This is where the input line
 * will be stored.
 * @line_size:a pointer to a size_t. This will hold the size of the buffer
 * that line points to.
 * @read: a pointer to a ssize_t. This will hold the number of characters
 * read from the input.
 * Return:
 */
void read_line(char **line, size_t *line_size, ssize_t *read)
{
	char *func = "read_line";
	*line = NULL;
	*line_size = 0;
	*read = getline(line, line_size, stdin);
	if (*read == -1)
	{
		if (feof(stdin))
		{
			if (isatty(STDIN_FILENO))
				printf("\n");
			if (*line != NULL)
				freestring(*line, func);
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("Error: getline");
			if (*line != NULL)
				freestring(*line, func);
			exit(EXIT_FAILURE);
		}
	}
	else if (*read == 1)
	{
		printf("$ ");
	}
}
