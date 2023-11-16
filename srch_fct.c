#include "shell.h"

/**
 * search_function - funtion that filter a command
 * @cmd: the array of commands
 * Return: NULL or existing command
 *
*/

char *search_function(char **cmd)
{
	char *command = NULL, *path, *folder;
	int i = 0, j;

	for (i = 0; cmd[i]; i++)
	{
		for (j = 0; cmd[i][j]; j++)
		{
			if (cmd[i][j] == '/')
			{
				command = strdup(cmd[i]);
				if (check_command(command) == 0)
					return (command);
				free(command);
				return (NULL);
			}
		}
	} path = get_path();
	folder = strtok(path, ":");
	for (i = 0; cmd[i]; i++)
	{
		if (folder)
			command = malloc(strlen(cmd[i]) + strlen(folder) + 2);
		if (command == NULL)
		{
			free(path);
			return (NULL);
		} while (folder)
		{
			strcpy(command, folder);
			strcat(command, "/");
			strcat(command, cmd[i]);
			if (check_command(command) == 0)
			{
				free(path);
				return (command);
			} folder = strtok(NULL, ":");
		} free(command), command = NULL;
	}
	free(path);
	return (NULL);
}
