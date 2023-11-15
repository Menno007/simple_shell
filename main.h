#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <stdarg.h>
#include <limits.h>

extern char **environ;
void _puts(char *str);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
char *_getenv(char *env_var);
void free_grid(char **grid);

char *rm_newline(char *input);
void print_env(void);
char **arg_handle(char *input);
char *find_path(char *cmd);
char *input_handle(char *input);
char *find_pwd(char *input);
int cases_handle(char *input, int read);
char *_strtok(char *string, const char *del);


#define BUFF_SIZE 1024

int _printf(const char *format, ...);
int print_char(char c);
int print_string(const char *str);
int print_percent(void);
int print_format(char format, va_list args);
int print_int(int integer);

#endif
