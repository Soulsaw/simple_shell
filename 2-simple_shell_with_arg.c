#include "main.h"
#include <stdlib.h>
#include <signal.h>
#include <string.h>
/**
 * execute_process - This function execute a command
 * @pid: This is the pointer to the pid
 * @argv: Is the aeguments
 */
void execute_process(pid_t *pid, char *argv[])
{
	int status;
	*pid = fork();
	if (*pid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror(__FILE__);
			exit(1);
		}
	}
	else
	{
		waitpid(*pid, &status, 0);
	}
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
	char *argv[] = {NULL, NULL, NULL};
	char *cmd = NULL, *str1, *token;
	size_t len;
	int i = 0, cpt = 0, j;
	pid_t myPid;

	while (1)
	{
		printf("#cisfun$ ");
		if (getline(&cmd, &len, stdin) == -1)
		{
			break;
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
		argv[2] = NULL;
		execute_process(&myPid, argv);
	}
	return (0);
}
