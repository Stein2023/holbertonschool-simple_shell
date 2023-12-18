#include "main.h"
/**
 * freedom - function to free each element of an array.
 * @array: array to be freed.
 * @name: size of the array.
 * Return:
 */
void freedom(char **array, char *name)
{
	(void)name;
	if (array != NULL)
		{	
	int count = 0;
		while (array[count] != NULL) 
		{	
			freestring(array[count], name);
			++count;
		}
	freestring(array[count], name);
	free(array);
	array = NULL;
	}
}

/**
 * freestring - function
 * @string: string to be freed
 * @name: name of funtion where array comes from
 * return: void
 */

void freestring(char * string, char *name)
{
	(void)name;
if (string != NULL)
	{
	free(string);
	string = NULL;
	}
}
