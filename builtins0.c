#include "shell.h"

/**
 * add_environment_variable - create a new environment variable
 * @vars: pointer to struct of variables
 *
 * Return: void
 */
void add_environment_variable(vars_t *vars)
{
	unsigned int i;
	char **newenv;

	for (i = 0; vars->env[i] != NULL; i++)
		;
	newenv = malloc(sizeof(char *) * (i + 2));
	if (newenv == NULL)
	{
		print_error_msg(vars, NULL);
		vars->status = 127;
		run_exit(vars);
	}
	for (i = 0; vars->env[i] != NULL; i++)
		newenv[i] = vars->env[i];
	newenv[i] = create_env_variable(vars->av[1], vars->av[2]);
	if (newenv[i] == NULL)
	{
		print_error_msg(vars, NULL);
		free(vars->buffer);
		free(vars->commands);
		free(vars->av);
		free_shell_env(vars->env);
		free(newenv);
		exit(127);
	}
	newenv[i + 1] = NULL;
	free(vars->env);
	vars->env = newenv;
}

/**
 * find_env_variable - finds an environment variable
 * @env: array of environment variables
 * @key: environment variable to find
 *
 * Return: pointer to address of the environment variable
 */
char **find_env_variable(char **env, char *key)
{
	unsigned int i, j, key_len;

	key_len = string_length(key);
	for (i = 0; env[i] != NULL; i++)
	{
		for (j = 0; j < key_len; j++)
			if (key[j] != env[i][j])
				break;
		if (j == key_len && env[i][j] == '=')
			return (&env[i]);
	}
	return (NULL);
}

/**
 * create_env_variable - create a new environment variable string
 * @key: variable name
 * @value: variable value
 *
 * Return: pointer to the new string;
 */
char *create_env_variable(char *key, char *value)
{
	unsigned int key_len, value_len, i, j;
	char *new_env_var;

	key_len = string_length(key);
	value_len = string_length(value);
	new_env_var = malloc(sizeof(char) * (key_len + value_len + 2));
	if (new_env_var == NULL)
		return (NULL);
	for (i = 0; key[i] != '\0'; i++)
		new_env_var[i] = key[i];
	new_env_var[i] = '=';
	for (j = 0; value[j] != '\0'; j++)
		new_env_var[i + 1 + j] = value[j];
	new_env_var[i + 1 + j] = '\0';
	return (new_env_var);
}

/**
 * convert_string_to_integer - converts a string into an integer
 * @str: string to convert
 *
 * Return: the integer value, or -1 if an error occurs
 */
int convert_string_to_integer(char *str)
{
	unsigned int i, digits;
	int num = 0, num_test;

	num_test = INT_MAX;
	for (digits = 0; num_test != 0; digits++)
		num_test /= 10;
	for (i = 0; str[i] != '\0' && i < digits; i++)
	{
		num *= 10;
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		if ((i == digits - 1) && (str[i] - '0' > INT_MAX % 10))
			return (-1);
		num += str[i] - '0';
		if ((i == digits - 2) && (str[i + 1] != '\0') && (num > INT_MAX / 10))
			return (-1);
	}
	if (i > digits)
		return (-1);
	return (num);
}
