#include "main.h"
/**
 * main - The entry point of program
 * Return: Always 0.
 */
int main(void)
{
	char *cmd = NULL;/** The variable stock the command line */
	size_t len, cpt;/** cpt can permit to change the last char to '\0'*/
	int i;
	pid_t myPid;

	while (1)
	{
		printf("#cisfun$ ");
		if (getline(&cmd, &len, stdin) == -1)
		{
			break;
		}
		cpt = 0;
		i = 0;
		while (cmd[i] != '\0')
		{
			cpt++;
			i++;
		}
		cmd[cpt - 1] = '\0';
		char *argv[] = { cmd, NULL};

		execute_process(&myPid, argv);
	}
	free(cmd);
	return (0);
}
