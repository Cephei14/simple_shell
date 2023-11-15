#include "shell.h"

/**
 * Dfree - function that free 2D array
 * @arr: 2d array to be freed
 * Return: nothing
*/

void Dfree(char **arr)
{
	int i = 0;

	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
