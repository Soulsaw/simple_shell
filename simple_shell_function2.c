#include "header.h"

/**
 * printstr - This function print the str in the terminal
 * @str: The string that we want to print
 * Return: Nothing
 */
void printstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}
/**
 * strlenght - This function return the lenght of the string
 * @str: The string that we want to return the lenght
 * Return: The lenght of the string
*/
int strlenght(char *str)
{
	int cpt = 0, i;

	i = 0;
	while (str[i] != '\0')
	{
		cpt++;
		i++;
	}
	return (cpt);
}
/**
 * strcpy_cpy - This function copy a string source to destination
 * @dest: Is the destination string
 * @src: Ist the source string
 * Return: The destination string
*/
char *strcpy_cpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/**
 * getnbwordstr - This function return the number of the in the str
 * @str: The string that we want to get number of words
 * Return: The number of words in the string
*/
int getnbwordstr(char *str)
{
	/**
	 * At begining i will copy the str to another string
	 * because at the end of this function i don't want
	 * to alter the str
	 * strlenght(str) + 1 : For the '\0' at the end of word
	*/
	char *strcpy, *str1, *token;
	int i;

	if (str == NULL)
		return (0);
	strcpy = (char *)malloc((strlenght(str) + 1) * sizeof(char));
	strcpy_cpy(strcpy, str);
	for (i = 0, str1 = strcpy; ; i++, str1 = NULL)
	{
		token = strtok(str1, " ");
		if (token == NULL)
			break;
	}
	free(strcpy);
	return (i);
}
/**
 * freealloc - This function permit to free the malloc
 * @argv: The pointer to the pointer of char
 * Return: Nothing
*/
void freealloc(char **argv)
{
	int i;

	if ((argv) != NULL)
	{
		for (i = 0; (argv)[i] != NULL; i++)
		{
			free((argv)[i]);
		}

		free(argv);
	}
}
