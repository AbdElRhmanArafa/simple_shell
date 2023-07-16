#include "simple_shell.h"
/**
 * prompt - use to display in interactive mode
 *@path: path.
 *
 * Return - void
 */
void prompt(char *path)
{
	_puts(path);
	_puts(" $ ");
	fflush(stdout);
}
/**
 * parse_input - split input
 *
 * @input: input will be pases
 * Return: token Array of string
 */
char **parse_input(char *input)
{
	int bufsize = 64;
	int position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	token = _strtok(input, " \t\n");
	while (token != NULL)
	{
		tokens[position] = _strdup(token);
		position++;

		if (position >= bufsize)
		{
			bufsize += 64;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				perror("realloc");
				exit(EXIT_FAILURE);
			}
		}

		token = _strtok(NULL, " \t\n");
	}
	tokens[position] = NULL;
	return (tokens);
}
