#include "simple_shell.h"
/**
 * _start_with - Checks if the string s1 starts with s2
 * @s1: The main string
 * @s2: The string to check for at the start of s1
 *
 * Return: 1 if s1 starts with s2, 0 otherwise
 */
int _start_with(char *s1, char *s2)
{
	while (*s2)
	{
		if (*s1 != *s2)
			return (0);
		s1++;
		s2++;
	}
	return (1);
}

/**
 * _strncpy - Copies at most 'len' characters from the string 's2' to 's1'
 * @s1: Destination string
 * @s2: Source string
 * @len: Maximum number of characters to be copied
 * Return: Pointer to the destination string 's1'
 */
char *_strncpy(char *s1, char *s2, int len)
{
	int i;

	for (i = 0; i < len && s2[i] != '\0'; i++)
		s1[i] = s2[i];
	for (; i < len; i++)
		s1[i] = '\0';
	return (s1);
}

/**
 * _strncat - Concatenates at most 'len' characters
 * from the string 's2' to 's1'
 * @s1: Destination string
 * @s2: Source string
 * @len: Maximum number of characters to be concatenated
 * Return: Pointer to the destination string 's1'
 */
char *_strncat(char *s1, char *s2, int len)
{
	int i, j;

	for (i = 0; s1[i] != '\0'; i++)
		;
	for (j = 0; j < len && s2[j] != '\0'; j++)
		s1[i + j] = s2[j];
	s1[i + j] = '\0';
	return (s1);
}

/**
 * _strchr - Locates the first occurrence of character 's1' in string 's2'
 * @s: Character to be found
 * @c: int  to be searched
 * Return: Pointer to the first occurrence of 's1'in's2'
 * or NULL if not found
 */
char *_strchr(char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return (s);
		s++;
	}

	if (c == '\0')
		return (s);

	return (NULL);
}

/**
 * is_delim - checks if a character is a delimiter
 * @c: the character to check
 * @delim: the delimiter string
 *
 * Return: 1 if the character is a delimiter, 0 otherwise
 */
int is_delim(char c, char *delim)
{
	while (*delim != '\0')
	{
		if (c == *delim)
			return (1);
		delim++;
	}
	return (0);
}
