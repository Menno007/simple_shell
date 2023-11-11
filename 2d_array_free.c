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
