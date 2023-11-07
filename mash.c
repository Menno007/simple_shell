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
	int read, PID;
	size_t len = 0, counter = 0;

	while (1)
	{
		counter++;
		if (isatty(STDIN_FILENO))
			printf("Minno&HYPER~$ ");

		read = getline(&input, &len, stdin);
		input = rm_newline(input);
		argv = arg_handle(input);

		if (read == -1)
			break;
		if (_strcmp(input, "exit") == 0)
			break;
		if (_strcmp(input, "env") == 0)
			print_env(envp);

		else
		{
			PID = fork();
			if (PID == 0)
			{
				if (execve(input, argv, envp) == -1)
				{
					printf("%s: %ld: %s: not found\n", argv[0], counter, input);
					break;
				}
			}
			else
				wait(NULL);
		}
		free(argv);
	}
	free(argv);
	free(input);
	return (0);
}
