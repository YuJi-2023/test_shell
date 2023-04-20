#include <stdio.h>
#include <string.h>
#include <unistd.h>
/**
 * _getenv - a function that gets an environment variable
 * @name: pointer to the name of the env variable to be fetched
 * Return: NULL if not found; pointer to the corresponding value string
 */
char *_getenv(const char *name)
{
        extern char **environ;
        char * str;
        int i;

        i = 0;
        while (environ[i] != NULL)
        {
                str = strtok(environ[i], "=");
                if (strcmp(str,  name) == 0)
                {
                        str = strtok(NULL, "=");
                        return (str);
                }
                i = i + 1;
        }
        return (NULL);
}

/**
 * _print_dir - a function that prints each dir contained in varialbe PATH
 *
 * Return: 0 on success
 */
int _print_dir()
{
	char *str;
	char *dir;
	str = _getenv("PATH");
	printf("here is the full path: %s\n", str);
	dir = strtok(str, ":");
	printf("see single dir below ========\n");
	while (dir != NULL)
	{
		printf("%s\n", dir);
		dir = strtok(NULL, ":");
	}
	return (0);
}
/**
 * main - check code above
 *
 * Return: 0
 */
int main()
{
	_print_dir();
	return (0);
}
