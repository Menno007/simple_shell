#include "main.h"
char *find_path(char *input);
/**
 * find_path - a function that serches
 *      for the a given file path in the
 *      PATH env variable path list
 *
 * @input: the given coommand
 *
 * Return: the full path of a command
 */
char *find_path(char *input)
{
	char *path = _getenv("PATH");
	char *token, *PATH_COPY;
	char *full_path, input_copy[1024];
	size_t cmd_len, path_len;

	PATH_COPY = malloc(sizeof(char) * (strlen(path) + 1));
	strcpy(PATH_COPY, path);
	_strcpy(input_copy, input);

	if (PATH_COPY == NULL)
		return (input);

	if (input == NULL)
		return (input);

	token = strtok(PATH_COPY, ":");

	while (token != NULL)
	{
		path_len = strlen(token);
		cmd_len = strlen(input_copy);

		full_path = malloc(path_len + cmd_len + 2);
		if (full_path == NULL)
			return (input);

		strcpy(full_path, token);
		strcat(full_path, "/");
		strcat(full_path, input_copy);

		if (access(full_path, F_OK | X_OK) == 0)
		{
			/*strcpy(input, full_path)
			free(full_path);*/
			free(PATH_COPY);
			return (full_path);
		}
		token = strtok(NULL, ":");
		free(full_path);
	}
	free(PATH_COPY);
	return (full_path);
}
