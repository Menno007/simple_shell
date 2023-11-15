#include "main.h"
/**
 * free_grid - frees a 2 dimensional grid
 * @grid: the grid
 */
void free_grid(char **grid)
{
	int i;

	for (i = 0; grid[i] != NULL; i++)
		free(grid[i]);
	free(grid);
}
#include "main.h"
/**
 * _puts - function
 * @str: first parameter
 * Return: 0 (Success)
 */
void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		putchar(str[i]);
	}
	putchar('\n');
}
