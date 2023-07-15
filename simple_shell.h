#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

/**
 * libararies
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/**const */
#define BUFFER_SIZE 1024
#define MAX_INPUT_LENGTH 256
#define MAX_PATH_LENGTH 256
extern char **environ;
/** string module function 1*/
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
char *_strcpy(char *dest, const char *src);
/** string module function 2*/
int _start_with(const char *s1, const char *s2);
char *_strncpy(char *s1, char *s2, int len);
char *_strncat(char *s1, char *s2, int len);
char *_strchr(char *s2, int c);
int is_delim(char c, const char *delim);
/**  read / write  module function 3*/
int _putchar(char c);
void _puts_NewLine(char *);
void _puts(char *);
char *my_getline(void);
char *_strtok(char *s, const char *delim);
/*** shell_utils function*/
void prompt(char *path);
char **parse_input(char *input);
/*** executor function*/
void execute_command(char **args);
void execute_external_command(char **args);
/**builtins.c*/
void execute_exit(char **args);
void execute_env(char **args);
void execute_setenv(char **args);
void execute_unsetenv(char **args);
void execute_cd(char **args);
/**hleper function helper_cd.c*/
int is_directory(char *path);
int change_directory(char *path);
int update_directory_env(char *current_path, char *previous_path);
void change_current_directory(char *path);
/** Mode_of_shell.c*/
void handle_noninteractive_mode(int argc, char *argv[]);
void handle_interactive_mode(void);
#endif /*SIMPLE_SHELL_H*/
