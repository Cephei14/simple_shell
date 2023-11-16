#include "shell.h"

/**
 * main - a simple shell
 * @ac: number of args
 * @progname: used to get the name of the first arg
 * Return: 0
 */

int main(int ac, char **progname)
{
	char *text = NULL, **cmd, *command;
	int sts, n = 1;

	(void)ac;
	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");
		text = full_line();
		if (text == NULL)
		{
			if (isatty(STDIN_FILENO))
				putchar(10);
			return (sts);
		}
		cmd = split_line(text);
		if (cmd == NULL)
		{
			n++;
			continue;
		}
		command = search_function(cmd);
		if (command == NULL)
		{
			sts = 127;
			fprintf(stderr, "%s: %d: %s: not found\n", progname[0], n, cmd[0]);
			free(command);
			Dfree(cmd);
			n++;
			continue;
		}
		sts = execute(cmd, command, progname, n);
		n++;
	}
}
