#include "main.h"
/**
 * print_env - prints the eviron var list
*/
void print_env(void)
{
	int i = 0;

	if (!environ)
		return;

	while (*environ)
	{
		_puts(environ[i]);
		i++;
	}
}
