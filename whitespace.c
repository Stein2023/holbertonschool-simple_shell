#include "main.h"
/**
 * iswhite - function to check if the recieved string is only made
 * of whitespaces.
 * @str: string to be checked.
 * Return: 1 if the string is only filled with whitespace characters,
 * otherwise 0.
 */
int iswhite(const char *str)
{
	while (*str != '\0')
	{
		if (strspn(str, " \t\n") != strlen(str))
			return (0);
		str++;
	}
	return (1);
}
