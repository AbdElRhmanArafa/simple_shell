#include "simple_shell.h"
/**
 * execute_exit - to terminate from shell with status
 * @args: command to execute
 * Return: void
 */
void execute_exit(char **args)
{
	int status = 0;

	if (args[1] != NULL)
	{
		status = atoi(args[1]);
		exit(status);
	}
	exit(EXIT_SUCCESS);
}
/**
 * execute_env - print environment varible
 *
 * @args: command line
 * Return: void
 */
void execute_env(char **args)
{
	char **env = environ;

	while (*env != NULL)
	{
		_puts_NewLine(*env);
		env++;
	}
	(void)args;
}
/**
 * execute_setenv - use this function to set varible in environment
 *
 * @args: command line
 * Return: void
 */
void execute_setenv(char **args)
{
	if (args[1] == NULL || args[2] == NULL)
	{
		fprintf(stderr, "Usage: setenv Varible value\n");
		return;
	}
	if (setenv(args[1], args[2], 1) == -1)
	{
		perror("setenv");
	}
}
/**
 * execute_unsetenv - use this function to unset varible in environment
 *
 * @args: command line
 * Return: void
 */
void execute_unsetenv(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "Usage: unsetenv Varible value\n");
		return;
	}
	if (unsetenv(args[1]) == -1)
		perror("unsetenv");
}
/**
 * execute_cd - use this function to change directory
 *
 * @args: command line
 * Return: void
 */
void execute_cd(char **args)
{
	char *previous_path, *home_path;

	if (args[1] == NULL || _strcmp(args[1], "~") == 0)
	{
		home_path = getenv("HOME");
		if (home_path == NULL)
		{
			fprintf(stderr, "cd: HOME not set\n");
			return;
		}
		change_current_directory(home_path);
	}
	else if (_strcmp(args[1], "-") == 0)
	{
		previous_path = getenv("OLDPWD");
		if (previous_path == NULL)
		{
			fprintf(stderr, "cd: OLDPWD not set\n");
			return;
		}
		change_current_directory(previous_path);
	}
	else
	{
		if (!is_directory(args[1]))
		{
			fprintf(stderr, "cd: %s: No such directory\n", args[1]);
			return;
		}
		change_current_directory(args[1]);
	}
}
