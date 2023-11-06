#include "main.h"
/**
 * input_handle - a function that handels the user input in multiple ways
 *
 * @input: the user input
 *
 * Return: the handeld input
 */
char *input_handle(char *input)
{
	input = rm_getline_newline(input);
	remove_spaces(input);

	if (strcmp(input, "ls") == 0)
	{
		input = find_cmd_path(input);
		return (input);
	}

	if (strcmp(input, "cd") == 0)
	{
		input = find_cmd_path(input);
		printf("%s", input);
		return (input);
	}

	else
		remove_spaces(input);
		return (input);
}
