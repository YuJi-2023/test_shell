#include <stdio.h>
/**
 * main - print all arguments
 *
 * Return: 0
 */
int main(int ac, char **av)
{
	while (*av != NULL)
	{
		printf("%s\n", *av);
		av = av + 1;
	}
	return (0);
}
