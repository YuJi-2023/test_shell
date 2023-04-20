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
