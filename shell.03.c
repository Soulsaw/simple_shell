#include "main.h"
/**
 * command - This function return the command
 * @cmd: The command whith \n
 * Return: The command
 */
char *command(char *cmd)
{
	int i, cpt;

	i = 0;
	cpt = 0;
	while (cmd[i] != '\0')
	{
		cpt++;
		i++;
	}
	cmd[cpt - 1] = '\0';
	return (cmd);
}
/**
 * init_argv - Initialize the argv in NULL
 * @arg: The array of string
 * Return: nothing
 */
void init_argv(char **arg)
{
	int i = 0;

	while (i < 4)
	{
		arg[i] = NULL;
		i++;
	}
}
/**
 * main - The entry point of program
 * @ac: The size of av array
 * @av: The arrat
 * @env: The env the content of the env
 * Return: Always 0.
 */
int main(int ac, char **av, char **env)
{
	char *argv[] = {NULL, NULL, NULL, NULL};
	char *cmd = NULL, *str1, *token;
	size_t len;
	int i;
	pid_t myPid;

	while (1)
	{
		printf("#cisfun$ ");
		if (getline(&cmd, &len, stdin) == -1)
			break;
		cmd = command(cmd);
		if (exit_cmd(cmd) == 0)
			break;
		if (env_cmd(cmd) == 0)
			_env(env);
		init_argv(argv);
		for (i = 0, str1 = cmd; ; i++, str1 = NULL)
		{
			token = strtok(str1, " ");
			if (token == NULL)
				break;
			argv[i] = token;
		}
		if (argv[2] == NULL)
		{
			execute_process(&myPid, argv, av[ac - 1]);
		}
		else
		{
			argv[3] = NULL;
			if (access(argv[0], X_OK) == -1)
				continue;
			execute_process(&myPid, argv, av[ac - 1]);
		}
	}
	return (0);
}
