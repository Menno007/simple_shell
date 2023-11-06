#include "main.h"
/**
 * main - the main function for the shell project
 *
 * Return: 0 om succes
 */
int main(int __attribute__((unused))argc, char **argv, char **env)
{
	char *buffer = NULL, *args, *cmd;
	int read, PID, arg_count = 0;
	size_t len = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("($) ");

		read = getline(&buffer, &len, stdin); 

		buffer = input_handle(buffer);

		if (read == -1)
			break;

		if (strcmp(buffer, "exit") == 0)
			return(0);
		else
		{
			PID = fork();
            if (PID == 0)
            {
                if (execve(buffer, argv, env) == -1)
                    perror(buffer);
            }
            else
                wait(NULL);
		}
	}
	free(buffer);
	return (0);
}
