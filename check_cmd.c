#include "shell.h"

/**
 * check_command - function that check if command exist
 * @command: the command
 * Return: 0 if not found, 1 if found
*/

int check_command(char *command)
{
	int n;
	struct stat ln;

	n = stat(command, &ln);
	if (n == 0)
	{
		return (0);
	}
	return (1);
}
