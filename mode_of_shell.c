#include "simple_shell.h"
/**
 * handle_noninteractive_mode - use pipline
 * @argc: number of argument
 * @argv: command that pass
 * Return: void
 */
void handle_noninteractive_mode(int argc, char *argv[])
{
	char *input, **args;
	ssize_t input_length;

	if (argc > 1)
	{
		input = argv[1];
		input_length = _strlen(input);
	}
	else
	{
		input = my_getline();
		input_length = _strlen(input);
	}
	if (input_length > 0 && input[input_length - 1] == '\n')
		input[input_length - 1] = '\0';

	args = parse_input(input);
	if (args != NULL)
		execute_command(args);

	free(input);
}

/**
 * handle_interactive_mode - handle user interactive
 * Return: void
 */
void handle_interactive_mode(void)
{
	char *input, **args;

	while (1)
	{
		prompt(getenv("PWD"));
		input = my_getline();
		args = parse_input(input);
		if (args == NULL)
			break;
		execute_command(args);
	}
}
