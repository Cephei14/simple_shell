#include "shell.h"

/**
 * main - a simple shell
 * @ac: number of args
 * @progname: used to get the name of the first arg
 * Return: 0
 */

int main(int ac, char **progname)
{
	char *text = NULL;
	char **cmd;
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
		sts = execute(cmd, progname, n);
		n++;
	}
	return (sts);
}
