#include <stdio.h>
#include <unistd.h>
extern char **environ;
/** 
 * main - prints the address of env and environ for comparison
 *
 * Return: 0
 */
int main(int ac, char **av, char **env)
{
	char *address_of_env;
	char *address_of_environ;

	address_of_env = *env;
	address_of_environ = *environ;
	printf("the address of env is: %s\n", address_of_env);
	printf("the address of environ is: %s\n", address_of_environ);
	return (0);
}


