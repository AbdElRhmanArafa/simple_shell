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

/** string module function 1*/
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
int *_start_with(const char *s1, const char *s2);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
/** string module function 2*/
char *_strncpy(char *s1, char *s2, int len);
char *_strncat(char *s1, char *s2, int len);
char *_strchr(char *s2, char *s1);
/**  read / write  module function 3*/
int _putchar(char c);
void _puts_NewLine(char *);
void _puts(char *);
char *my_getline();
char *_strtok(char *s, const char *delim);
#endif /*SIMPLE_SHELL_H*/
