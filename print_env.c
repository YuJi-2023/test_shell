#include<stdio.h>
#include<unistd.h>
extern char **environ;
/**
 * main - prints the environment using environ
 * Return: 0
 */
int main()
{
	int i;

	i = 0;
	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i = i + 1;
	}
	return (0);
}
