#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>

char *full_line();
char **split_line(char *text);
int execute(char **cmd, char **progname, int n);
void Dfree(char **arr);
int search_function(char *src);

extern char **environ;

#endif

