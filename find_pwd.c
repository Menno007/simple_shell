#include "main.h"
/**
 * find_pwd - a function that serches
 *      for the a given file path in the
 *      PATH env variable path list
 *
 * @input: the given coommand
 *
 * Return: the full path of a command
 */
char *find_pwd(char *input)
{
	char *pwd = _getenv("PWD");
	char *full_path;
	size_t input_len, pwd_len;


	if (pwd == NULL)
		return (input);

	if (input == NULL)
		return (input);

	input_len = _strlen(input);
	pwd_len = _strlen(pwd);

	full_path = malloc(sizeof(char) * (input_len + pwd_len));
	if (full_path == NULL)
	return (input);


	strcpy(full_path, pwd);
	strcat(full_path, &input[1]);

	if (access(full_path, F_OK | X_OK) == 0)
	{
		strcpy(input, full_path);
		free(full_path);
		return (input);
	}
	free(full_path);
	return (input);
}
