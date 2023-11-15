#include "main.h"
/**
 * HYPERs_free - memory leak killer
 *
 * @argv: arg vector
 */
void HYPERs_free(char **argv)
{
	int i;

	for (i = 0; argv[i] != NULL; i++)
	{
		free(argv[i]);
	}
	free(argv);
}
