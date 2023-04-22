#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
/**
 * main - looks for files in the current PATH
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
    char *path;
    char *token;
    int i;
    struct stat st;
    char filename[1024];
    char filepath[1024];

    path = getenv("PATH");
    printf("path is :::::::%s\n", path);

    if (ac < 2)
    {
        printf("please enter file to search\n");
        return (1);
    }

    i = 1;
    token = strtok(path, ":");
    while (token != NULL)
    {
        while (i < ac)
        {
            strcpy(filename, av[i]);
            strcpy(filepath, token);
	    strcat(filepath, "/");
	    strcat(filepath, filename);
            if (stat(filepath, &st) == 0)
            {
                printf("%s\n", filepath);
            }
            i = i + 1;
        }
        i = 1;
        token = strtok(NULL, ":");
    }
    if (token == NULL)
    {
	    printf("NO MATCHING\n");
    }
    return 0;
}

