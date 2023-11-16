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
int execute(char **cmd, char *command, char **progname, int n);
void Dfree(char **arr);
char *search_function(char **src);
char *get_path();
int check_command(char *command);

extern char **environ;

#endif

