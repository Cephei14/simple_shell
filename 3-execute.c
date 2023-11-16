#include "shell.h"

/**
 * execute - function that execute a command
 * @cmd: NULL terminated strings
 * @progname: first arg value aka name of the program
 * @n: a number that count the command executed
 * Return: status of the execution
*/

int execute(char **cmd, char *command, char **progname, int n)
{
	pid_t child;
	int status;

	child = fork();
	if (child == -1)
	{
		perror("fork failed\n");
		return (127);
	}
	if (child == 0)
	{
		if (execve(command, cmd, environ) == -1)
		{
			printf("%s: %d: %s: not found\n", progname[0], n, cmd[0]);
			exit(127);
		}
	}
	else
	{
		waitpid(child, &status, 0);
		free(command);
		Dfree(cmd);
	}
	return (WEXITSTATUS(status));
}
