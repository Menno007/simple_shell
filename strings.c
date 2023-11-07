#include "main.h"
/**
 * _strlen - function to swap 2 values
 * @s: first parameter
 * Return: 0 (Success);
 */
int _strlen(char *s)
{
	int sum = 0;

	for (; *s != '\0'; s++)
		sum++;

	return (sum);
}
/**
 * _strcmp - compares two strings
 * @s1: first string to compare
 * @s2: second string to compare
 *
 * Return: less than 0 if s1 is less than s2, 0 if they're equal,
 * more than 0 if s1 is greater than s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
			return (0);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
/**
 * _strcpy - copies the string pointed to by stc to dest
 * @dest: pointer of char to be checked
 * @src: another pointer of char to be check
 * Return: 0 (Success)
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}

	if (src[i] == '\0')
		dest[i] = src[i];

	return (dest);
}
/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 * @str: the source string
 *
 * Return: returns a pointer to the duplicated string.
 * It returns NULL if insufficient memory was available
 */
char *_strdup(char *str)
{
	char *duplicate;
	/*int i = 0;*/
	unsigned long int j;

	if (str == NULL)
		return (NULL);

	duplicate = malloc((sizeof(char) * strlen(str)) + 1);
	if (duplicate == NULL)
		return (NULL);
	for (j = 0; j < strlen(str); j++)
	{
		duplicate[j] = str[j];
	}
	duplicate[j] = '\0';

	return (duplicate);
}
/**
 * _strcat - returns a pointer to a concenatde string
 * @dest: string.
 * @src: source str
 *
 * Return: pointer of an array of chars
 */
char *_strcat(char *dest, char *src)
{
	char *p = dest;

	while (*p)
		p++;
	while (*src)
	{
		*p = *src;
		p++;
		src++;
	}
	*p = '\0';
	return (dest);
}
