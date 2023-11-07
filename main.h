#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);

char *rm_newline(char *input);
void print_env(char **envp);
char **get_args(char *input);
char **arg_handle(char *input);

char *find_cmd_path(char *cmd);
char *input_handle(char *input, char *cmd, char **argv);
char *remove_spaces(char *input);


#endif
