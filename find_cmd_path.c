#include "main.h"
/**
 * find_cmd_path - a function that serches
 *      for the a given command path in the
 *      PATH env variable path list
 *
 * @cmd: the given coommand
 *
 * Return: the full path of a command
 */
char *find_cmd_path(char *cmd)
{
	char *path = getenv("PATH");
	char *token;

	if (path == NULL)
		return (NULL);

	token = strtok(path, ":");

	while (token != NULL)
	{
		size_t path_len = strlen(token);
		size_t cmd_len = strlen(cmd);

		char *full_path = malloc(path_len + cmd_len + 2);

		if (full_path == NULL)
			return (NULL);

		strcpy(full_path, token);
		strcat(full_path, "/");
		strcat(full_path, cmd);

		if (access(full_path, F_OK | X_OK) == 0)
		{
			return (full_path);
		}

		free(full_path);
		token = strtok(NULL, ":");
	}

	return (NULL);
}

char **handle_arg(char *buffer)
{
	int i, num = 0;
	char **result;

	for (i = 0; buffer[i]; i++)
	{
		printf("%c\n", buffer[i]);
		if (buffer[i] == ' ')
		{
			num++;
		}
	}
	result = malloc(sizeof(char *) * num + 1);
	result[0] = strtok(buffer, " ");
	i = 0;
	while (result[i])
	{
		result[i] = strtok(NULL, " ");
	}

	return (result);
}
