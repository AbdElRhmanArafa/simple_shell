#include "main_shell.h"
/**
 * run_cd - Change directory (cd) built-in function
 * @vars: Pointer to the vars_t structure containing arguments and environment
 *Return: void
 */
void run_cd(vars_t *vars)
{
	char *path = vars->av[1];

	if (path == NULL)
		path = getenv("HOME");

	if (path == NULL)
	{
		perror("cd");
		return;
	}

	if (chdir(path) == -1)
	{
		perror("cd");
		return;
	}
}
