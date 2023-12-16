#include "main.h"
/**
 * tokenize_line - function to split the line into tokens.
 * @line: line to be tokenized.
 * @array: to store the tokens as parameters.
 * Return: number of tokens.
 */

int tokenize_line(char *line, char **array)
{
	char *token;
	int i = 0;

	if (line == NULL)
		return (0);
	token = strtok(line, " \t\n");
	while (token)
	{
		array[i] = strdup(token);
		token = strtok(NULL, " \t\n");
		i++;
	}
	return (i);
}
