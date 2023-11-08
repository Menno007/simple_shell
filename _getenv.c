#include "main.h"
/**
 * _getenv - function to get environment
 * @env_var: the environment variable name
 * Return: a pointer to environment value, or NULL if there is no match.
*/
char *_getenv(char *env_var)
{
	int j, i;
	char *spretor;
	int back;

	back = _strlen(env_var);

	if (!env_var)
		return (NULL);

	for (i = 0; environ[i] != NULL; i++)
	{
		for (j = 0; (j < back) && (env_var[j] == environ[i][j]); j++)
		{
			;
		}
		if (j == back && environ[i][j] == '=')
		{
			return (environ[i] + j + 1);
		}
	}
	return (NULL);
}
