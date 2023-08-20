#include "header.h"
/**
 * getcommand - This function permit to get commande type by the user
 * Return: The command string
 */
char *getcommand(void)
{
	char *line = NULL;
	size_t len;
	ssize_t nread;
	int strlen;

	nread = getline(&line, &len, stdin);
	if (nread == -1)
	{
		return (NULL);
	}
	strlen = strlenght(line);
	line[strlen - 1] = '\0';

	return (line);
}
/**
 * executecommand - This function permit to execute a command
 * @name: The execute file name
 * @env: This is the environement variable
 * Return: -1 0 or 1
 */
int executecommand(char *name, char **env)
{
	char **argv = NULL;

	getcommandarg(&argv);
	if (argv == NULL)
	{
		freealloc(argv);
		return (-1);
	}
	create_process(&argv, name, env);
	return (0);
}
/**
 * execute - this function display a prompt wait for a user to type command
 * @name: Is the name of the execute file
 * @env: This is the environement variable
 * Return: Nothing
 */
void execute(char *name, char **env)
{
	int status;

	while (1)
	{
		printstr("");
		status = executecommand(name, env);
		if (status == -1)
			break;
	}
}
/**
 * getcommandarg - This function found a command and these arguments in the str
 * @argv: This function take a pointer to a pointer to a pointer in argument
 * Return: Nothing
*/
void getcommandarg(char ***argv)
{
	int i, wordlenght;
	char *cmd, *str, *token;

	cmd = getcommand();
	wordlenght = getnbwordstr(cmd);
	*argv = (char **)malloc((wordlenght + 1) * sizeof(char *));
	for (i = 0, str = cmd; ; i++, str = NULL)
	{
		token = strtok(str, " ");
		if (token == NULL)
			break;
		(*argv)[i] = (char *)malloc((strlenght(token) + 1) * sizeof(char));
		strcpy_cpy((*argv)[i], token);
	}
	(*argv)[wordlenght] = NULL;
	free(cmd);
}

/**
 * strcmpstr - This function compare two string
 * @s1: Is the first string
 * @s2: Is the second string
 * Return: 0 if the two string is equals
*/
int strcmpstr(char *s1, char *s2)
{
	int boolean, i;

	i = 0;
	boolean = 0;
	for (i = 0; s1[i] != '\0'; i++)
	{
		if (s2[i] == '\0')
		{
			return (-1);
		}
		if (s1[i] != s2[i])
		{
			boolean = 1;
		}
	}
	if (s2[i] != '\0')
	{
		return (2);
	}
	return (boolean);
}
