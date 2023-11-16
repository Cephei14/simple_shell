#include "shell.h"

/**
 * get_path -function that get the path
 * Return: string containing the path
 */

char *get_path()
{
	int i = 0, j = 0;
	char st[4], *temp_env = NULL;

	while (environ[i])
	{
		j = 0;
		while (j < 4)
		{
			st[j] = environ[i][j];
			j++;
		}
		st[j] = '\0';
		if (strcmp(st, "PATH") == 0)
		{
			temp_env = strdup(environ[i] + 5);
			return (temp_env);
		}
		i++;
	}
	return (NULL);
}
