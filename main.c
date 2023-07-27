#include "main_shell.h"

/**
 * sig_handler - handles ^C signal interupt
 * @sig: signal number
 *
 * Return: void
 */
static void sig_handler(int sig)
{
	if (sig == SIGINT)
		print_string("\n$ ");
}

/**
 * main - main function for the shell
 * @argc: number of arguments passed to main (unused)
 * @argv: array of arguments passed to main
 * @environment: array of environment variables
 *
 * Return: 0 or exit status, or ?
 */
int main(int argc, char **argv, char **environment)
{
	size_t len_buffer = 0;
	unsigned int is_pipe = 0, i;
	vars_t vars = {NULL, NULL, NULL, 0, NULL, 0, NULL};
	struct sigaction sa;

	vars.argv = argv;
	vars.env = create_shell_env(environment);
	sa.sa_handler = sig_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	if (sigaction(SIGINT, &sa, NULL) == -1)
		perror("sigaction");
	if (!isatty(STDIN_FILENO))
		is_pipe = 1;
	if (is_pipe == 0)
		print_string("$ ");
	while (getline(&(vars.buffer), &len_buffer, stdin) != -1)
	{
		vars.count++;
		vars.commands = tokenize(vars.buffer, ";");
		for (i = 0; vars.commands && vars.commands[i] != NULL; i++)
		{
			vars.av = tokenize(vars.commands[i], "\n \t\r");
			if (vars.av && vars.av[0])
				if (find_builtin_function(&vars) == NULL)
					check_for_path(&vars);
			free(vars.av);
		}
		free(vars.buffer);
		free(vars.commands);
		if (is_pipe == 0)
			print_string("$ ");
		vars.buffer = NULL;
	}
	if (is_pipe == 0)
		print_string("\n");
	free_shell_env(vars.env);
	free(vars.buffer);
	exit(vars.status);
	(void)argc;
}
