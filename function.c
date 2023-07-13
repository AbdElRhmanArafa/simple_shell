#include "simple_shell.h"
/**
 * _strlen - returns the length of a string
 * @s: string
 * Return: length
 */
int _strlen(char *s)
{
	int longi = 0;

	while (*s != '\0')
	{
		longi++;
		s++;
	}

	return (longi);
}
/**
 * _strcmp - compare string values
 * @s1: input value
 * @s2: input value
 *
 * Return: s1[i] - s2[i]
 */
int _strcmp(char *s1, char *s2)
{

	while (*s1 == *s2)
	{
		if (*s1 == '\0')
		{
			return (0);
		}
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
/**
 * _strcat - concatenates two strings
 * @dest: input value
 * @src: input value
 *
 * Return: void
 */
char *_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	dest[i] = '\0';
	return (dest);
}
/**
 * _strdup - duplicate to new memory space location
 * @str: char
 * Return: 0
 */

char *_strdup(char *str)
{
	char *new_str;
	int i, len;

	if (str == NULL)
		return (NULL);

	for (len = 0; str[len] != '\0'; len++)
		;

	new_str = malloc(sizeof(char) * (len + 1));

	if (new_str == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
		new_str[i] = str[i];

	return (new_str);
}
