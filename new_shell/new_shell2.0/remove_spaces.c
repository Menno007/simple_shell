#include "main.h"
/**
 * remove_spaces - removes spaces at the start and the end of a string
 * @input: the inputed string
 * Return: the cleam string
 */
char *remove_spaces(char *input)
{
	int length;
	int i, shiftIndex = 0;
	char *start = NULL;
	int found = 0;

	length = strlen(input);

	for (i = 0; i < length; i++)
	{
		if (input[i] != ' ' && input[i] != '\t')
		{
			start = &input[i];
			found = 1;
			break;
		}
	}

	if (!found)
	{
		return (NULL);
	}

	if (start != NULL)
	{
		for (i = start - input; i < length; i++)
		{
			input[shiftIndex] = input[i];
			shiftIndex++;
		}
		input[shiftIndex] = '\0';
	}

	return (input);
}
