#include "main.h"
/**
 * main - The entry point of program
 *
 * Return: Always 0.
 *
 *
 */
int main(void)
{
	char *cmd = NULL, *str1, *token;
	size_t len;
	int i, cpt, j;
	pid_t myPid;

	while (1)
	{
		printf("#cisfun$ ");
		if (getline(&cmd, &len, stdin) == -1)
		{
			break;
		}
		i = 0;
		cpt = 0;
		while (cmd[i] != '\0')
		{
			cpt++;
			i++;
		}
		cmd[cpt - 1] = '\0';
		char *argv[] = {NULL, NULL, NULL};

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
	free(cmd);
	return (0);
}
