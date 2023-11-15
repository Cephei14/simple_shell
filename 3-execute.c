#include "shell.h"

/**
 * execute - function that execute a command
 * @cmd: NULL terminated strings
 * @progname: first arg value aka name of the program
 * @n: a number that count the command executed
 * Return: status of the execution
*/

int execute(char **cmd, char **progname, int n)
{
	pid_t child;
	int status;

	child = fork();
	if (child == -1)
	{
		perror("fork failed\n");
		return (-1);
	}
	if (child == 0)
	{
		if (execve(cmd[0], cmd, environ) == -1)
		{
			printf("%s: %d: not found\n", progname[0] + 2, n);
			Dfree(cmd);
			exit(127);
		}
	}
	else
	{
		waitpid(child, &status, 0);
		Dfree(cmd);
	}
	return (WEXITSTATUS(status));
}
