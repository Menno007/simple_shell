#include "main.h"
/**
 * print_string - prints a percent
 * @str: string
 * Return: int
 */
int print_string(const char *str)
{
	int count = 0;

	if (str == NULL)
	{
		count += write(1, "(null)", 6);
		return (count);
	}

	while (*str)
	{
		write(1, str, 1);
		str++;
		count++;
	}
	return (count);
}
