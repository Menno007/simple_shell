#include "main.h"
/**
 * rm_newline - a function to remove
 *          the extra newline created by the getline function
 *
 * @input: a buffer that holds the user input
 *
 * Return: returns the user input without the new line
 */
char *rm_newline(char *input)
{
	size_t line_length = _strlen(input);

	if (line_length > 0 && input[line_length - 1] == '\n')
		input[line_length - 1] = '\0';

	return (input);
}
