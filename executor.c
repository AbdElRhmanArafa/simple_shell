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
	char *path, *token, *program_path;
	pid_t pid;
	int status;
	struct stat st;

	path = getenv("PATH");
	if (path == NULL)
	{
		fprintf(stderr, "PATH Environment Not Set\n");
		return;
	}
	token = _strtok(path, ":");
	while (token != NULL)
	{
		program_path = malloc(MAX_PATH_LENGTH);
		snprintf(program_path, MAX_PATH_LENGTH - 1, "%s/%s", token, args[0]);
		if (stat(program_path, &st) == 0 && st.st_mode & S_IXUSR)
		{
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
		free(program_path);
		token = _strtok(NULL, ":");
	}
	fprintf(stderr, "%s: command not found\n", args[0]);
}
