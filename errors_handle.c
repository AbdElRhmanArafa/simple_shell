#include "shell.h"


/**
 * print_error_msg - prints error messages to standard error
 * @vars: pointer to struct of variables
 * @msg: message to print
 *
 * Return: void
 */
void print_error_msg(vars_t *vars, char *msg)
{
	char *count_str;

	_puts_stderr(vars->argv[0]);
	_puts_stderr(": ");
	count_str = _uitoa_str(vars->count);
	_puts_stderr(count_str);
	free(count_str);
	_puts_stderr(": ");
	_puts_stderr(vars->av[0]);
	if (msg)
	{
		_puts_stderr(msg);
	}
	else
		perror("");
}

/**
 * _puts_stderr - prints a string to standard error
 * @str: string to print
 *
 * Return: void
 */
void _puts_stderr(char *str)
{
	ssize_t num, len;

	num = string_length(str);
	len = write(STDERR_FILENO, str, num);
	if (len != num)
	{
		perror("Fatal Error");
		exit(1);
	}

}

/**
 * _uitoa_str - converts an unsigned int to a string
 * @count: unsigned int to convert
 *
 * Return: pointer to the converted string
 */
char *_uitoa_str(unsigned int count)
{
	char *numstr;
	unsigned int tmp, digits;

	tmp = count;
	for (digits = 0; tmp != 0; digits++)
		tmp /= 10;
	numstr = malloc(sizeof(char) * (digits + 1));
	if (numstr == NULL)
	{
		perror("Fatal Error1");
		exit(127);
	}
	numstr[digits] = '\0';
	for (--digits; count; --digits)
	{
		numstr[digits] = (count % 10) + '0';
		count /= 10;
	}
	return (numstr);
}
