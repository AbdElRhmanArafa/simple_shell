#include "shell.h"

/**
 * print_string - writes a string to standard output
 * @str: string to write
 *
 * Return: number of characters printed or -1 on failure
 */
ssize_t print_string(char *str)
{
	ssize_t num_chars, len;

	num_chars = string_length(str);
	len = write(STDOUT_FILENO, str, num_chars);
	if (len != num_chars)
	{
		perror("Fatal Error");
		return (-1);
	}
	return (len);
}

/**
 * duplicate_string - returns a pointer to new memory allocated space that contains a copy of the input string
 * @original: string to be duplicated
 *
 * Return: a pointer to the new duplicated string
 */
char *duplicate_string(char *original)
{
	char *copy;
	int len, i;

	if (original == NULL)
		return (NULL);

	for (len = 0; original[len]; len++)
		;
	copy = malloc((len + 1) * sizeof(char));

	for (i = 0; i <= len; i++)
		copy[i] = original[i];

	return (copy);
}

/**
 * compare_strings - compares two strings
 * @str1: first string to be compared
 * @str2: second string to be compared
 *
 * Return: 0 on success, anything else is a failure
 */
int compare_strings(char *str1, char *str2)
{
	int i;

	i = 0;
	while (str1[i] == str2[i])
	{
		if (str1[i] == '\0')
			return (0);
		i++;
	}
	return (str1[i] - str2[i]);
}

/**
 * concatenate_strings - concatenates two strings
 * @str1: first string
 * @str2: second string
 *
 * Return: pointer to the concatenated string
 */
char *concatenate_strings(char *str1, char *str2)
{
	char *new_string;
	unsigned int len1, len2, new_len, i, j;

	len1 = 0;
	len2 = 0;
	if (str1 == NULL)
		len1 = 0;
	else
	{
		for (len1 = 0; str1[len1]; len1++)
			;
	}
	if (str2 == NULL)
		len2 = 0;
	else
	{
		for (len2 = 0; str2[len2]; len2++)
			;
	}
	new_len = len1 + len2 + 2;
	new_string = malloc(new_len * sizeof(char));
	if (new_string == NULL)
		return (NULL);
	for (i = 0; i < len1; i++)
		new_string[i] = str1[i];
	new_string[i] = '/';
	for (j = 0; j < len2; j++)
		new_string[i + 1 + j] = str2[j];
	new_string[len1 + len2 + 1] = '\0';
	return (new_string);
}

/**
 * string_length - returns the length of a string
 * @str: string to be measured
 *
 * Return: length of the string
 */
unsigned int string_length(char *str)
{
	unsigned int len;

	len = 0;

	for (len = 0; str[len]; len++)
		;
	return (len);
}