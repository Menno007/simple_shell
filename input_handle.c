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
	if (strncmp(input, "/", 1) != 0)
	{
		input = find_path(input);
		return (input);
	}
	if (strncmp(input, ".", 1) != 0)
	{
		input = find_pwd(input);
		return (input);
	}
	else
		return (input);
}
