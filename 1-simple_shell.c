#include "main.h"
#include <stdlib.h>
#include <signal.h>
void kill_process(pid_t pid)
{
	kill(pid, SIGTERM);
	sleep(1);
	kill(-pid, SIGKILL);
}
/**
 * main - The entry point of program
 *
 * Return: Always 0.
 *
 *
 */
int main(void)
{
	char *argv[] = {NULL, NULL};
	char *cmd = NULL;
	size_t len;
	int i = 0, cpt = 0, status;
	pid_t myPid;

	while (1)
	{
		myPid = fork();
		if (myPid == 0)
		{
			printf("#cisfun$ ");
			if (getline(&cmd, &len, stdin) == -1)
			{
				perror(__FILE__);
			}
			while (cmd[i] != '\0')
			{
				cpt++;
				i++;
			}
			cmd[cpt - 1] = '\0';
			argv[0] = cmd;
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror(__FILE__);
			}
		}
		else
		{
			wait(&status); /** The parent process wait
					* then childreen process terminate
					*/
		}
	}
	return (0);
}
