#include "main.h"
/**
 * freedom - function to free each element of an array.
 * @array: array to be freed.
 * @size: size of the array.
 * Return:
 */
void freedom(char **array, char *name)
{
if (array != NULL)
	{	
int count = 0;
	while (array[count] != NULL) 
	{	
		 printf("freeing %s string from array[%i] in %s\n", array[count], count, name);
		freestring(array[count], name);
		++count;
	}
	printf("freeing %s string from array[%i] in %s\n", array[count], count, name);
	freestring(array[count], name);
	printf("FREE EMPTY ARRAY");
	free(array);
	array = NULL;
	}
}

void freestring(char * string, char *name)
{
	printf("freeing %s string in %s\n", string, name);
if (string != NULL)
	{
	free(string);
	string = NULL;
	}
}
