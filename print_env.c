#include "main.h"
/**
 * print_env - prints the eviron var list
*/
void print_env(void)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		write(1, environ[i], strlen(environ[i]));
		write(1, "\n", 1);
	}

}
