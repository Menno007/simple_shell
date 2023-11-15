#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 50

extern char **environ;

int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
char *_getenv(char *env_var);

char *rm_newline(char *input);
void print_env(char **envp);
char **arg_handle(char *input);
char *find_path(char *cmd);
char *input_handle(char *input);
char *find_pwd(char *input);
int cases_handle(char *input, int read, char **envp);
char *remove_spaces(char *input);

void HYPERs_free(char **argv);



#endif
