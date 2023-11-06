#include "main.h"
/**
 * arg_handle - handels arguments
 * 
 * @buffer: the whole blob of the command compined with its 
 * 
 */
int arg_handle(char *buffer, char *cmd, char **argv)
{
    int arg_count = 0;
    char *token;
    char *temp;

    cmd = strtok(buffer, " ");

    if (cmd == NULL)
    {
        return (1);
    }

    token = strtok(NULL, " ");

    while (token != NULL)
    {
        arg_count++;
        token = strtok(NULL, " ");
    }
    
    argv = malloc((arg_count + 1) * sizeof(char *));

    temp = strtok(buffer, " ");

    for (int i = 0; i < arg_count + 1; i++)
    {
        temp = strtok(NULL, " ");
        argv[i] = temp;
    }

    argv[arg_count + 1] = NULL;
    

}
