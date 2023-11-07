#include "main.h"
/**
 * arg_handle - handels arguments
 * @input: the whole blob of the command compined with its args
 * Return: the arg vector
 */
char **arg_handle(char *input)
{
	int arg_count = 0, i;
	char **argv, *token, *tmp, input_copy[1024];

	if (!input)
		return (NULL);

	strcpy(input_copy, input);

	tmp = strtok(input_copy, " ");

	if (tmp == NULL)
		return (0);

	while (tmp != NULL)
	{
		arg_count++;
		tmp = strtok(NULL, " ");
	}

	argv = (char **)malloc((arg_count + 2) * sizeof(char *));
	if (argv == NULL)
		return (0);

	strcpy(input_copy, input);
	argv[0] = strtok(input_copy, " ");

	for (i = 1; i <= arg_count; i++)
	{
		token = strtok(NULL, " ");
		argv[i] = token;
	}

	argv[arg_count + 1] = NULL;

	strcpy(input, argv[0]);

	return (argv);
}
