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
	char *input = NULL, **args = NULL, __attribute__((unused))**test = NULL;
	int read, PID, status, exit_status;
	size_t len = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("Minno&HYPER~$ ");
		read = getline(&input, &len, stdin);
		input = rm_newline(input);
		/*input = remove_spaces(input);*/
		if (input == NULL)
			continue;
		if (cases_handle(input, read, envp) == -1)
			break;

		else
		args = arg_handle(input);
		{
			PID = fork();
			if (PID == 0)
			{
				input = input_handle(input);
				if (execve(input, args, envp) == -1)
				{
					fprintf(stderr, "%s: 1: %s: not found\n", argv[0], input);
					exit(127);
				}
			}
			else
				waitpid(PID, &status, 0);
			exit_status = WEXITSTATUS(status);
		}
		HYPERs_free(args);
	}
	free(input);
	if (exit_status != 0)
		return (127);
	return (0);
}
