#include "main.h"
char **arg_handle(char *input);
#define safe_free(freedom)\
{\
	free(freedom);\
	freedom = NULL;\
}
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
	tmp = _strtok(input_copy, " \t");
	if (tmp == NULL)
	{
		free(input_copy);
		return (NULL);
	}
	while (tmp != NULL)
	{
		arg_count++;
		tmp = _strtok(NULL, " \t");
	}
	safe_free(input_copy);
	input_copy = malloc(sizeof(char) * (input_len + 1));
	argv = (char **)malloc((arg_count + 1) * sizeof(char *));
	if (argv == NULL)
	{
		free(input_copy);
		return (NULL);
	}
	strcpy(input_copy, input);
	token = _strtok(input_copy, " \t");
	for (i = 0; token != NULL; i++)
	{
		argv[i] = strdup(token);
		if (argv[i] == NULL)
		{
			free(input_copy);
			free(*argv);
			free(argv);
			return (NULL);
		}
		token = _strtok(NULL, " \t");
	}
	argv[arg_count] = NULL;
	free(input_copy);
	return (argv);
}
