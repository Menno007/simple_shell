#include "main.h"
/**
 * main - the main function for the shell project
 *
 * Return: 0 om succes
 */
int main(int __attribute__((unused))argc, char **argv, char **env)
{
	char *buffer = NULL;
	int read, PID;
	size_t len = 0;
	char **args;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");

		read = getline(&buffer, &len, stdin);

		buffer = input_handle(buffer);
		if (read == -1)
			break;

		if (strcmp(buffer, "exit") == 0)
			break;
		else if (!strcmp(buffer, "env"))
			print_env(env);
		else
		{
			args = handle_arg(buffer);
			printf("%s\n%s\n", args[0], args[1]);
			PID = fork();
			if (PID < 0)
			{
				perror("Fork failed");
				exit(1);
			}
			if (PID == 0)
			{
				if (execve(buffer, argv, env) == -1)
					perror(buffer);
					break;
			}
			else
				wait(NULL);
		}
	}
	free(buffer);
	return (0);
}
