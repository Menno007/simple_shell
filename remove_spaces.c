#include "main.h"
/**
 *
 *
 */
char *remove_spaces(char *input)
{
	int length;
	int i, j = 0;

	length = strlen(input);

	for (i = 0; i < length; i++)
	{
		if (input[i] != ' ')
		{
			input[j] = input[i];
			j++;
		}
	}
	input[j] = '\0';
	return (input);
}
