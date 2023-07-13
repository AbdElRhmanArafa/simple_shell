#include "simple_shell.h"

/**
 * _putchar - writes a character to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts_NewLine - prints a string, followed by a new line, to stdout
 * @str: string to print
 */
void _puts_NewLine(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str++);
	}
	_putchar('\n');
}

/**
 * _puts - prints a string, followed by a new line, to stdout
 * @str: string to print
 */
void _puts(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str++);
	}
}

/**
 * _strtok - used to split string into tokens based on a specified delimiter.
 * @s: string of array
 * @delim: specified delimiter
 * Return: string
 */
char *_strtok(char *s, const char *delim)
{
	static char *next_token;
	char *token_start = s;

	if (s == NULL)
		s = next_token;

	if (s == NULL)
		return (NULL);

	while (is_delim(*s, delim))
	{
		s++;
	}

	if (*s == '\0')
	{
		next_token = NULL;
		return (NULL);
	}

	while (*s != '\0' && !is_delim(*s, delim))
	{
		s++;
	}

	if (*s == '\0')
		next_token = NULL;
	else
	{
		*s = '\0';
		next_token = s + 1;
	}

	return (token_start);
}

/**
 * my_getline - reads a line of input from stdin
 *
 * Return: the line read from stdin, or NULL on failure or end of input
 */
char *my_getline(void)
{
	static char buffer[BUFFER_SIZE];
	static int buffer_index;
	static int buffer_size;

	char *line = NULL;
	int line_size = 0;
	int c;

	while (1)
	{
		if (buffer_index >= buffer_size)
		{
			buffer_size = read(STDIN_FILENO, buffer, BUFFER_SIZE);
			buffer_index = 0;
			if (buffer_size == 0)
				return (line);
		}

		c = buffer[buffer_index++];

		if (c == '\n' || c == EOF)
		{
			if (line == NULL)
				return (line);

			line[line_size] = '\0';
			return (line);
		}

		line = realloc(line, (line_size + 1) * sizeof(char));
		line[line_size++] = c;
	}
}
