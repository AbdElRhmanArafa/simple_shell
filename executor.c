#include "simple_shell.h"
/**
 * execute_command - Check for build-in commands
 * @args: command to check
 * Return: void
 */
void execute_command(char **args)
{
	if (_strcmp(args[0], "exit") == 0)
	{
		execute_exit(args);
		return;
	}
	else if (_strcmp(args[0], "env") == 0)
	{
		execute_env(args);
		return;
	}
	else if (_strcmp(args[0], "cd") == 0)
	{
		execute_cd(args);
		return;
	}
	else if (_strcmp(args[0], "setenv") == 0)
	{
		execute_setenv(args);
		return;
	}
	else if (_strcmp(args[0], "unsetenv") == 0)
	{
		execute_unsetenv(args);
		return;
	}
	else if (_strcmp(args[0], "alias") == 0)
	{
		return;
	}
	else
	{
		execute_external_command(args);
	}
}
/**
 * 
*/
void execute_external_command(char **args)
{
	(void)args;
	return;
}
