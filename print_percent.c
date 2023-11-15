#include "main.h"
/**
 * print_percent - prints a percent
 *
 * Return: %
 */

int print_percent(void)
{
	char percent = '%';

	return (write(1, &percent, 1));
}
