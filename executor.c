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
 * find_program_path - find the path of a program
 * @program_name: name of the program to find
 * @path: the PATH environment variable
 * Return: the path of the program, or NULL if not found
 */
char *find_program_path(char *program_name, char *path)
{
	char *token, *program_path;
	struct stat st;

	token = _strtok(path, ":");
	while (token != NULL)
	{
		program_path = malloc(MAX_PATH_LENGTH);
		if (program_path == NULL)
		{
			perror("malloc");
			return (NULL);
		}
		_strcpy(program_path, token);
		_strcat(program_path, "/");
		_strcat(program_path, program_name);
		if (stat(program_path, &st) == 0 && st.st_mode & S_IXUSR)
		{
			return (program_path);
		}
		free(program_path);
		token = _strtok(NULL, ":");
	}
	return (NULL);
}

/**
 * execute_command_help_for_external - execute a command
 * @program_path: path of the program to execute
 * @args: arguments to the program
 * Return: void
 */
void execute_command_help_for_external(char *program_path, char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execvp(program_path, args) == -1)
		{
			perror("execvp");
			free(program_path);
			exit(EXIT_FAILURE);
		}
	}
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		free(program_path);
		return;
	}
	else
	{
		perror("fork");
		free(program_path);
		return;
	}
}

/**
 * execute_external_command - execute external command
 * @args: command to be executed
 * Return: void
 */
void execute_external_command(char **args)
{
	char *path, *program_path, *copy_path;

	path = getenv("PATH");
	if (path == NULL)
	{
		perror("PATH Environment Not Set\n");
		return;
	}
	copy_path = _strdup(path);
	program_path = find_program_path(args[0], copy_path);
	if (program_path == NULL)
	{
		perror(args[0]);
		return;
	}

	execute_command_help_for_external(program_path, args);
}
