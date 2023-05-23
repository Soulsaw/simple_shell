#include "main.h"
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <errno.h>
/**
 * main - The entry point of program
 *
 * Return: Always 0.
 *
 *
 */
int main(void)
{
	char *argv[] = {NULL, NULL, NULL, NULL};
	char *cmd = NULL, *str1, *token;
	size_t len;
	int i = 0, cpt = 0, status, j;
	pid_t myPid;

	while (1)
	{
		myPid = fork();
		if (myPid == 0)
		{
			printf(":) ");
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
			for (j = 0, str1 = cmd; ; j++, str1 = NULL)
			{
				token = strtok(str1, " ");
				if (token == NULL)
					break;
				argv[j] = token;
			}
			argv[3] = NULL;
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
