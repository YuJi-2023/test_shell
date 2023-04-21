#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
/**
 * _execve - execute a program
 *
 * Return: 0 on success
 */
int _execve(char *user_input)
{
	char *argv[] = {user_input, NULL};

	printf("Before execve\n");

    if (execve(argv[0], argv, NULL) == -1)
    {
        perror("Error:");
    }
    printf("After execve\n");
    return (0);
}

/**
 * main - prints "$ ", waits for a users command to execute
 *
 * Return: 0
 */
int main ()
{
	size_t length;
	char *line_to_read;
	ssize_t read;
	pid_t child;
	int status;

	while (1)
	{
		line_to_read = NULL;
		length = 0;
		printf("$ ");
		read = getline(&line_to_read, &length, stdin);
		if (read == -1)
		{
			printf("%d\n", errno);
			free(line_to_read);
			return (-1);
		}
		line_to_read = strtok(line_to_read, "\n");

		child = fork();
		if (child == -1)
		{
			return (1);
		}
		if (child == 0)
		{
			_execve(line_to_read);
		}
		else
		{
			wait(&status);
			printf("mission accomplished!!\n");
		}
		free(line_to_read);
	}
	return (0);
}
