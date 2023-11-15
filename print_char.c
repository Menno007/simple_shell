#include "main.h"
/**
 * print_char - prints a char
 * @c: a char
 * Return: char
 */
int print_char(char c)
{
	return (write(1, &c, 1));
}
