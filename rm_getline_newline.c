#include "main.h"
/**
 * rm_getline_newline - a function to remove
 *          the extra newline created by the getline function
 *
 * @buff: a buffer that holds the user input
 *
 * Return: returns the user input without the new line
 */
char *rm_getline_newline(char *buff)
{
	size_t line_length = strlen(buff);

	if (line_length > 0 && buff[line_length - 1] == '\n')
		buff[line_length - 1] = '\0';

	return (buff);
}
