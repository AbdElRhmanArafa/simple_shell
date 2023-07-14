#include "simple_shell.h"
/**
 * execute_command - Check for build-in commands
 * @args: command to check
 * Return: void
 */
void execute_command(char **args)
{
	if (_strcmp(args[0], "exit" == 0))
	{
	}
	else if (_strcmp(args[0], "env") == 0)
	{
		/* code */
	}
	else if (_strcmp(args[0], "cd") == 0)
	{
		/* code */
	}
	else if (_strcmp(args[0], "setenv") == 0)
	{
		/* code */
	}
	else if (_strcmp(args[0], "unsetenv") == 0)
	{
		/* code */
	}
	else if (_strcmp(args[0], "alias") == 0)
	{
	}
	else
	{
		execute_external_command(args);
	}
}
