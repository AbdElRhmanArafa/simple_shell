#include "shell.h"

/**
 * find_builtin_function - checks if the command is a builtin
 * @vars: variables
 * Return: pointer to the function or NULL
 */
/**
 * find_builtin_function - checks if the command is a builtin
 * @vars: variables
 * Return: pointer to the function or NULL
 */
void (*find_builtin_function(vars_t *vars))(vars_t *vars)
{
	unsigned int i;
	builtins_t builtins[] = {
		{"exit", run_exit},
		{"env", show_env},
		{"setenv", run_setenv},
		{"unsetenv", run_unsetenv},
		{NULL, NULL}};

	for (i = 0; builtins[i].name != NULL; i++)
	{
		if (_strcmpr(vars->av[0], builtins[i].name) == 0)
			break;
	}

	if (builtins[i].func != NULL)
		builtins[i].func(vars);

	return (builtins[i].func);
}
/**
 * run_exit - exit program
 * @vars: variables
 * Return: void
 */
void run_exit(vars_t *vars)
{
	int status;

	if (_strcmpr(vars->av[0], "exit") == 0 && vars->av[1] != NULL)
	{
		status = convert_string_to_integer(vars->av[1]);
		if (status == -1)
		{
			vars->status = 2;
			print_error(vars, ": Illegal number: ");
			_puts2(vars->av[1]);
			_puts2("\n");
			free(vars->commands);
			vars->commands = NULL;
			return;
		}
		vars->status = status;
	}

	free(vars->buffer);
	free(vars->av);
	free(vars->commands);
	free_shell_env(vars->env);
	exit(vars->status);
}

/**
 * show_env - prints the current environment
 * @vars: struct of variables
 * Return: void.
 */
void show_env(vars_t *vars)
{
	unsigned int i;

	for (i = 0; vars->env[i]; i++)
	{
		_puts(vars->env[i]);
		_puts("\n");
	}
	vars->status = 0;
}

/**
 * run_setenv - create a new environment variable, or edit an existing variable
 * @vars: pointer to struct of variables
 *
 * Return: void
 */
void run_setenv(vars_t *vars)
{
	char **key;
	char *var;

	if (vars->av[1] == NULL || vars->av[2] == NULL)
	{
		print_error(vars, ": Incorrect number of arguments\n");
		vars->status = 2;
		return;
	}

	key = find_env_variable(vars->env, vars->av[1]);
	if (key == NULL)
		add_environment_variable(vars);
	else
	{
		var = create_env_variable(vars->av[1], vars->av[2]);
		if (var == NULL)
		{
			print_error(vars, NULL);
			free(vars->buffer);
			free(vars->commands);
			free(vars->av);
			free_shell_env(vars->env);
			exit(127);
		}
		free(*key);
		*key = var;
	}
	vars->status = 0;
}

/**
 * run_unsetenv - remove an environment variable
 * @vars: pointer to a struct of variables
 *
 * Return: void
 */
void run_unsetenv(vars_t *vars)
{
	char **key, **newenv;

	unsigned int i, j;

	if (vars->av[1] == NULL)
	{
		print_error(vars, ": Incorrect number of arguments\n");
		vars->status = 2;
		return;
	}

	key = find_env_variable(vars->env, vars->av[1]);
	if (key == NULL)
	{
		print_error(vars, ": No variable to unset");
		return;
	}

	for (i = 0; vars->env[i] != NULL; i++)
		;

	newenv = malloc(sizeof(char *) * i);
	if (newenv == NULL)
	{
		print_error(vars, NULL);
		vars->status = 127;
		run_exit(vars);
	}

	for (i = 0; vars->env[i] != *key; i++)
		newenv[i] = vars->env[i];

	for (j = i + 1; vars->env[j] != NULL; j++, i++)
		newenv[i] = vars->env[j];

	newenv[i] = NULL;
	free(*key);
	free(vars->env);
	vars->env = newenv;
	vars->status = 0;
}
