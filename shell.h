#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <limits.h>
#include <signal.h>

/**
 * struct variables - variables
 * @av: command line arguments
 * @buffer: buffer of command
 * @env: environment variables
 * @count: count of commands entered
 * @argv: arguments at opening of shell
 * @status: exit status
 * @commands: commands to execute
 */
typedef struct variables
{
	char *buffer;
	char **env;
	char **av;
	size_t count;
	char **argv;
	int status;
	char **commands;
} vars_t;

/**
 * struct builtins - struct for the builtin functions
 * @name: name of builtin command
 * @f: function for corresponding builtin
 */
typedef struct builtins
{
	char *name;
	void (*func)(vars_t *);
} builtins_t;

char **create_shell_env(char **env);
void free_shell_env(char **env);

ssize_t print_string(char *str);
char *duplicate_string(char *strtodup);
int compare_strings(char *strcmp1, char *strcmp2);
char *concatenate_strings(char *strc1, char *strc2);
unsigned int string_length(char *str);

char **tokenize(char *buffer, char *delimiter);
char **reallocate_array(char **ptr, size_t *size);
char *custom_strtok(char *str, const char *delim);

void (*find_builtin_function(vars_t *vars))(vars_t *vars);
void run_exit(vars_t *vars);
void show_env(vars_t *vars);
void run_setenv(vars_t *vars);
void run_unsetenv(vars_t *vars);

void add_environment_variable(vars_t *vars);
char **find_env_variable(char **env, char *key);
char *create_env_variable(char *key, char *value);
int convert_string_to_integer(char *str);
unsigned int is_character_in_string(char c, const char *str);


void check_for_path(vars_t *vars);
int path_execute(char *command, vars_t *vars);
char *find_path(char **env);
int execute_cwd(vars_t *vars);
int check_for_dir(char *str);

void print_error_msg(vars_t *vars, char *msg);
void _puts_stderr(char *str);
char *_uitoa_str(unsigned int count);

#endif 
