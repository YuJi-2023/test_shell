#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
/**
 * main - print $ sign, read line and print it out
 *
 * Return: 0 on success -1 on failure
 */
int main ()
{
	size_t length;
	char *line_to_read;
	ssize_t read;

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
	printf("%s", line_to_read);
	free(line_to_read);
	return (0);
}
