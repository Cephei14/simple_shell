#include "shell.h"

/**
 * full_line - function that wait until it takes input from the user
 * Return: pointer to the string
*/

char *full_line(void)
{
	ssize_t s;
	char *str = NULL;
	size_t n = 0, l = 0;

	s = getline(&str, &n, stdin);
	if (s == -1)
	{
		free(str);
		return (NULL);
	}
	l = strlen(str);
	str[l - 1] = '\0';
	if (s == EOF)
	{
		free(str);
		return (NULL);
	}
	return (str);
}
