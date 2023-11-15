#include "shell.h"

/**
 * split_line - funtion that split a sting into tokens
 * @str: the string to be divided
 * Return: 2D pointer to the tokens
*/

char **split_line(char *str)
{
	char **cmd, *t_cmd, *token, *delim = " \t\n";
	int i = 0, t = 0;

	t_cmd = strdup(str);
	token = strtok(t_cmd, delim);
	if (token == NULL)
	{
		free(str);
		free(t_cmd);
		return (NULL);
	}
	while (token)
	{
		t++;
		token = strtok(NULL, delim);
	}
	free(t_cmd);
	cmd = malloc(sizeof(char *) * (t + 1));
	if (cmd == NULL)
	{
		perror("malloc failed\n");
		free(str);
		exit(1);
	}
	token = strtok(str, delim);
	while (token)
	{
		cmd[i] = strdup(token);
		token = strtok(NULL, delim);
		i++;
	}
	free(str);
	cmd[i] = NULL;
	return (cmd);
}
