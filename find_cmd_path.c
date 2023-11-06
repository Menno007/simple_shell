#include "main.h"
/**
 * find_cmd_path - a function that serches
 *      for the a given command path in the
 *      PATH env variable path list
 *
 * @cmd: the given coommand
 *
 * Return: the full path of a command
 */
char *find_cmd_path(char *cmd)
{
    char *path = getenv("PATH");
    char *token;

    if (path == NULL)
        return NULL;

    token = strtok(path, ":");

    while (token != NULL)
    {
        size_t path_len = strlen(token);
        size_t cmd_len = strlen(cmd);

        char *full_path = malloc(path_len + cmd_len + 2);

        if (full_path == NULL)
            return NULL;

        strcpy(full_path, token);
        strcat(full_path, "/");
        strcat(full_path, cmd);

        if (access(full_path, F_OK | X_OK) == 0)
        {
            return (full_path);
        }

        free(full_path);
        token = strtok(NULL, ":");
    }

    return NULL;
}