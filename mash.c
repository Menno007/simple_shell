#include "main.h"
/**
 * main - the main function for the shell project
 *
 * @argc: arguments count
 * @argv: argument vector
 * @envp: environ vars vector
 *
 * Return: 0 om succes
 */
int main(int __attribute__((unused))argc, char *argv[], char *envp[])
{
	char *input = NULL;
	char **argu = NULL;
	int read, PID, counter = 0;
	size_t len = 0;

	while (1)
	{
		counter++;
		if (isatty(STDIN_FILENO))
			printf("Minno&HYPER~$ ");
		read = getline(&input, &len, stdin);
		input = rm_newline(input);
		argu = argv;
		argu = arg_handle(input);
		if (cases_handle(input, read, envp) == -1)
			break;

		else
		{
			PID = fork();
			if (PID == 0)
			{
				input = input_handle(argu[0]);
				/*printf("%s", argu[0]);
				printf("%s", input);*/
				if (execve(input, argu, envp) == -1)
				{
					printf("%s: %d: %s: not found\n", argv[0], counter, input);
					break;
				}
			}
			else
				wait(NULL);
		}
		free(argu);
		free(input);
	}
	free(argu);
	free(input);
	return (0);
}
