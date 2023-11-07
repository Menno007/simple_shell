#include "main.h"
/**
 * print_env - prints the eviron var list
 * @envp: the environ var list
*/
void print_env(char **envp)
{
	if (!envp)
		return;

	while (*envp)
	{
		printf("%s\n", *envp);
		envp++;
	}
}
