#include "main.h"
int main(int __attribute__((unused))argc, char *argv[], char *envp[]);

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
	char *check_access = NULL, *input = NULL;
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

		if (cases_handle(input, read, envp) == -1)
			break;

		else
		{
			argu = argv;
			argu = arg_handle(input);
			check_access = find_path(argu[0]);
			if (check_access != NULL)
			{
				free(check_access);
				PID = fork();
				if (PID == 0)
				{
					check_access = input_handle(argu[0]);
					if (execve(check_access, argu, envp) == -1)
					{
						printf("%s: %d: %s: not found\n", argv[0], counter, check_access);
						break;
					}
				}
				else
					wait(NULL);
			}
		}
		free(argu);
		free(input);
	}
	free(argu);
	return (0);
}
