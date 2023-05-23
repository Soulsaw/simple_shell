#include "main.h"
/**
 * main - The entry point of program
 * @ac: The size of av array
 * @av: The arrat
 * @env: The env the content of the env
 * Return: Always 0.
 */
int main(int ac, char **av, char **env)
{
	char *cmd = NULL, *str1, *token;
	size_t len;
	int i, cpt;
	pid_t myPid;

	while (1)
	{
		printf(":) ");
		if (getline(&cmd, &len, stdin) == -1)
			break;
		i = 0;
		cpt = 0;
		while (cmd[i] != '\0')
		{
			cpt++;
			i++;
		}
		cmd[cpt - 1] = '\0';
		if (exit_cmd(cmd) == 0)
			break;
		if (env_cmd(cmd) == 0)
			_env(env);
		char *argv[] = {NULL, NULL, NULL, NULL};

		for (i = 0, str1 = cmd; ; i++, str1 = NULL)
		{
			token = strtok(str1, " ");
			if (token == NULL)
				break;
			argv[i] = token;
		}
		argv[3] = NULL;
		if (access(argv[0], X_OK) == -1)
			continue;

		execute_process(&myPid, argv);
	}
	return (0);
}
