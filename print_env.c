#include "main.h"
/**
 * print_env - prints the eviron var list
*/
void print_env(void)
{
	int j = 0, i = 0;

	while (!environ[i])
	{
		for (; environ[i][j] != '\0' ; j++)
		{
			write(1, &environ[i][j], 1);
		}
		write(1, "\n", 1);
		i++;
	}
}
