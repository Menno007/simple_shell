#include "main.h"
/**
 * cases_handle - a functon that handels some speacheal cases
 *							for the shell project
 * @input: input
 * @read: getline return
 * Return: -1
 */

int cases_handle(char *input, int read)
{
	if (read == EOF)
		return (-1);
	if (_strcmp(input, "exit") == 0)
	{
		return (-1);
	}

	return (0);
}
