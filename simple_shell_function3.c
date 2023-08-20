#include "header.h"
/**
 * foundcommand - This function permit to found a command
 * @cmd: The command char
 * Return: 1 On success 0 on error
*/
int foundcommand(char *cmd)
{
	struct stat st;

	if (stat(cmd, &st) == 0)
		return (1);
	return (0);
}
/**
 * addpath - This function add the path in the command
 * @cmd: Is the command
 * Return: Char to the new command path
*/
char *addpath(char *cmd)
{
	int status, i;
	char *newcmd, str[] = "/bin/";

	newcmd = (char *)malloc((strlenght(cmd) + strlenght(str) + 1) * sizeof(char));
	for (i = 0; str[i] != '\0'; i++)
	{
		newcmd[i] = str[i];
	}
	status = i;
	for (i = 0; cmd[i] != '\0'; i++, status++)
	{
		newcmd[status] = cmd[i];
	}
	newcmd[status] = '\0';

	return (newcmd);
}
/**
 * _putchar - This function print a char in the output
 * @c: Is the char that we want to print
 * Return: The char
*/
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * exit_func - This function permit to quit the shell
 * @status: The status of the parent id
 * Return: Nothing
*/
void exit_func(int status)
{
	exit(status);
}
/**
 * create_process - This function permit to execute command
 * @argv: This is the array toa command whit argument
 * @name: This is the name of the execute file
 * @env: This is the environement variable
 * Return: Nothing
*/
void create_process(char ***argv, char *name, char **env)
{
	pid_t children;
	char *newcommand = NULL;
	int status;

	if (strcmpstr(*(argv)[0], "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	}
	if (strcmpstr(*(argv)[0], "env") == 0)
	{
		printenv(env);
	}
	if (foundcommand(*(argv)[0]) == 0)
	{
		newcommand = addpath(*(argv)[0]);
		*(argv)[0] = (char *)malloc((strlenght(newcommand) + 1) * sizeof(char));
		strcpy_cpy(*(argv)[0], newcommand);
		free(newcommand);
	}
	if (foundcommand(*(argv)[0]) == 1)
	{
		children = fork();
		if (children == 0)
		{
			if (execve(*(argv)[0], *argv, NULL) == -1)
			{
				perror(name);
			}
			freealloc(*argv);
		}
		else
		{
			wait(&status);
			freealloc(*argv);
		}
	}
}
