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
	if (input[0] == '/')
	{
		return (input);
	}
	else if (input[0] == '.')
	{
		input = find_pwd(input);
		return (input);
	}
	else if (input[0] == '.' && input[1] == '/')
	{
		return (input);
	}
	else
	{
		input = find_path(input);
		return (input);
	}
}
