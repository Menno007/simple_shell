#include "main.h"
/**
 * arg_handle - handels arguments
 * @input: the whole blob of the command compined with its args
 * Return: the arg vector
 */
char **arg_handle(char *input)
{
	int arg_count = 0, i, input_len;
	char **argv, *token, *tmp, *input_copy = NULL;

	if (!input)
		return (NULL);
	input_len = strlen(input);
	input_copy = malloc(sizeof(char) * (input_len + 1));
	if (input_copy == NULL)
		return (NULL);
	strcpy(input_copy, input);
	tmp = strtok(input_copy, " ");
	if (tmp == NULL)
		return (NULL);
	while (tmp != NULL)
	{
		arg_count++;
		tmp = strtok(NULL, " ");
	}
	free(input_copy);
	input_copy = NULL;
	argv = (char **)malloc((arg_count + 1) * sizeof(char *));
	if (argv == NULL)
	{
		free(input_copy);
		return (NULL);
	}
	strcpy(input_copy, input);
	argv[0] = strtok(input_copy, " ");
	for (i = 0; i < arg_count && token != NULL; i++)
	{
		argv[i] = strdup(token);
		token = strtok(NULL, " ");
		if (argv[i] == NULL)
		{
			free(input_copy);
			free(*argv);
			free(argv);
			return (NULL);
		}
	}
	argv[arg_count] = NULL;
	strcpy(input, argv[0]);
	free(input_copy);
	return (argv);
}
