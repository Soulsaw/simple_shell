#include "main.h"
/**
 * env_cmd - This function return 0 if the command is env and -1 else
 * @cmd: The command we want to test
 * Return: 0 or -1
 */
int env_cmd(char *cmd)
{
	int i, b = 0;
	char argv[] = "env";

	i = 0;
	while (cmd[i] != '\0')
	{
		if (cmd[i] != argv[i])
			b = -1;
		i++;
	}
	return (b);
}
/**
 * exit_cmd - This function return 0 if exit command is put and 1 else
 * @cmd: The command we want to check
 * Return: 0 or 1
 */
int exit_cmd(char *cmd)
{
	int i, b = 0;
	char argv[] = "exit";

	i = 0;
	while (cmd[i] != '\0')
	{
		if (cmd[i] != argv[i])
			b = 1;
		i++;
	}
	return (b);
}
/**
 * execute_process - This function execute a command
 * @pid: This is the pointer to the pid
 * @name: The name of the file executing
 * @argv: Is the aeguments
 */
void execute_process(pid_t *pid, char *argv[], char *name)
{
	int status;

	*pid = fork();
	if (*pid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			fprintf(stderr, "%s: ", name);
			perror("");
			exit(1);
		}
	}
	else
	{
		waitpid(*pid, &status, 0);
	}
}
/**
 * _env - This function print every env alue
 * @env: The array content all env value
 * Return: nothing
 */
void _env(char **env)
{
	int i = 0;

	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}
}
