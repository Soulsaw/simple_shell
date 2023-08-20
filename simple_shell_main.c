#include "header.h"
/**
 * main - The entry point of the project
 * @ac: The size of argument
 * @av: The array to the char argument
 * @env: This is the environement variable
 * Return: Success
*/
int main(int ac, char *av[], char **env)
{
	execute(av[ac - 1], env);
	return (0);
}
