#include "header.h"
/**
 * printenv - This function print the env
 * @env: This is the environnement value
 * Return:Nothing
*/
void printenv(char **env)
{
	unsigned int i;

	i = 0;
	while (env[i] != NULL)
	{
		printstr(env[i]);
		printstr("\n");
		i++;
	}
}
