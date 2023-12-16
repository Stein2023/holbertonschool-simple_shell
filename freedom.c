#include "main.h"
/**
 * freedom - function to free each element of an array.
 * @array: array to be freed.
 * @size: size of the array.
 * Return:
 */
void freedom(char **array, int size)
{
	int i;

	for (i = 0; i < size; i++)
	{
		free(array[i]);
	}
	free(array);
}
