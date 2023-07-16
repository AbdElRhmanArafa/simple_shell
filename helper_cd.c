#include "simple_shell.h"

/**
 * is_directory - Checks if a string is a valid directory path.
 *
 * @path: path to check
 * Return: 1 if the path exists and is a directory, 0 otherwise.
 */
int is_directory(char *path)
{
	struct stat st;

	if (stat(path, &st) == 0 && S_ISDIR(st.st_mode))
		return (1);
	return (0);
}
/**
 * change_directory - Changes the current working directory
 * to the specified path.
 * @path: path to check
 * Return: 1 on success, 0 on failure.
 */
int change_directory(char *path)
{
	if (chdir(path) == -1)
	{
		perror("chdir");
		return (0);
	}
	return (1);
}

/**
 * update_directory_env - Updates the environment variables PWD
 * and OLDPWD with the current and previous directories.
 *
 * @current_path: PWD change
 * @previous_path: OLDPWD Change
 * Return: 1 on success, 0 on failure.
 */
int update_directory_env(char *current_path, char *previous_path)
{
	if (setenv("PWD", current_path, 1) != 0)
	{
		perror("setenv");
		return (0);
	}

	if (setenv("OLDPWD", previous_path, 1) != 0)
	{
		perror("setenv");
		return (0);
	}

	return (1);
}
/**
 * get_absolute_path - get the absolute path of a directory
 * @path: the path to convert to an absolute path
 * @current_path: the current working directory
 * Return: the absolute path of the directory, or NULL if an error occurs
 */
char *get_absolute_path(char *path, char *current_path)
{
	char *absolute_path, *last_slash;

	if (path[0] == '/')
		absolute_path = _strdup(path);
	else
	{
		absolute_path = (char *)malloc(PATH_MAX * sizeof(char));
		if (absolute_path == NULL)
		{
			perror("malloc");
			return (NULL);
		}
		if (_strcmp(path, ".") == 0)
			_strcpy(absolute_path, current_path);
		else if (_strcmp(path, "..") == 0)
		{
			last_slash = strrchr(current_path, '/');
			if (last_slash != NULL)
			{
				*last_slash = '\0';
				_strcpy(absolute_path, current_path);
			}
			else
				absolute_path = _strdup("/");
		}
		else if (path[0] == '.' && (path[1] == '/' || path[1] == '\0'))
			_strcpy(absolute_path, current_path);
		else
		{
			_strcpy(absolute_path, current_path);
			_strcat(absolute_path, "/");
			_strcat(absolute_path, path);
		}
	}
	return (absolute_path);
}
/**
 * change_current_directory - change the current working directory
 * @path: the path to change to
 * Return: void
 */
void change_current_directory(char *path)
{
	char *current_path, *absolute_path, *previous_path;

	current_path = getcwd(NULL, 0);
	if (current_path == NULL)
	{
		perror("getcwd");
		return;
	}

	absolute_path = get_absolute_path(path, current_path);
	if (absolute_path == NULL)
	{
		free(current_path);
		return;
	}
	previous_path = current_path;
	if (!change_directory(absolute_path))
	{
		free(absolute_path);
		free(current_path);
		return;
	}
	if (!update_directory_env(absolute_path, previous_path))
		change_directory(previous_path);
	free(absolute_path);
	free(current_path);
}
