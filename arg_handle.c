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
	tmp = strtok(input_copy, " ");
	if (tmp == NULL)
		return (NULL);
	while (tmp != NULL)
	{
		arg_count++;
		tmp = strtok(NULL, " ");
	}
	safe_free(input_copy);
	printf("here?\n");
	input_copy = malloc(sizeof(char) * (input_len + 1));
	argv = (char **)malloc((arg_count + 2) * sizeof(char *));
	if (argv == NULL)
	{
		free(input_copy);
		return (NULL);
	}
	strcpy(input_copy, input);
	argv[0] = strtok(input_copy, " ");
	for (i = 1; i < arg_count && token != NULL; i++)
	{
		argv[i] = strdup(token);
		if (argv[i] == NULL)
		{
			free(input_copy);
			free(*argv);
			free(argv);
			return (NULL);
		}
		token = strtok(NULL, " ");
	}
	argv[arg_count] = NULL;
	printf("here? before strcp\n");
	strcpy(input, argv[0]);
	printf("here? after strcp\n");
	free(input_copy);
	return (argv);
}
