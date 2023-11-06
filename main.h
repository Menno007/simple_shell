#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

char *rm_getline_newline(char *buff);
char *find_cmd_path(char *cmd);
char *input_handle(char *input);
char **arg_handle(char *arg);

#endif
