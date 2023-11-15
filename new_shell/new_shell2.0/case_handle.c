#include "main.h"
/**
 * cases_handle - a functon that handels some speacheal cases
 *							for the shell project
 * @input: input
 * @read: getline return
 * @envp: env
 * Return: -1
 */

int cases_handle(char *input, int read, char **envp)
{
	if (read == EOF)
		return (-1);

	if (input == NULL)
		return (1);

	if (_strcmp(input, "exit") == 0)
		return (-1);

	if (_strcmp(input, "env") == 0)
		print_env(envp);

	return (0);
}
