#include "main.h"
/**
 * _strtok - function that tokenize a string
 *
 * @string: a string
 *
 * @del: delmiter
 *
 * Return: toknized atring
 */
char *_strtok(char *string, const char *del)
{
	return (strtok(string, del));
}
