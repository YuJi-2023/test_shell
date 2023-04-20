#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
/**
 * main - executes the command ls -l/tmp in 5 different child processes
 *
 * Return: 0
 */
int main()
{
	pid_t child;
	int status;
	int count = 0;
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};

	while (count < 5)
	{
		child = fork();
		if (child == -1)
		{
			return (1);
		}
		if (child == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
			{
				return (1);
			}
			else
			{
				return (0);
			}
		}
		else
		{
			wait(&status);
		}
		count = count + 1;
	}
	return (0);
}
