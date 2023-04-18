#include <stdio.h>
#include <unistd.h>
/**
 * main - print the PID of the parent process
 *
 * Return: 0
 */
int main(void)
{
	pid_t ppid;
	ppid = getppid();
	printf("%u\n", ppid);
	return (0);
}
