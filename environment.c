#include "shell.h"

/**
 * create_shell_env - create the shell environment from the environment passed to main
 * @env: environment passed to main
 *
 * Return: pointer to the new environment
 */
char **create_shell_env(char **env)
{
	char **shell_env = NULL;
	size_t i;

	for (i = 0; env[i] != NULL; i++)
		;
	shell_env = malloc(sizeof(char *) * (i + 1));
	if (shell_env == NULL)
	{
		perror("Fatal Error");
		exit(1);
	}
	for (i = 0; env[i] != NULL; i++)
		shell_env[i] = _strdup(env[i]);
	shell_env[i] = NULL;
	return (shell_env);
}

/**
 * free_shell_env - free the shell's environment
 * @env: shell's environment
 *
 * Return: void
 */
void free_shell_env(char **env)
{
	unsigned int i;

	for (i = 0; env[i] != NULL; i++)
		free(env[i]);
	free(env);
}
