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
		fprintf(stderr, "Failed to update the PWD environment variable\n");
		return (0);
	}

	if (setenv("OLDPWD", previous_path, 1) != 0)
	{
		fprintf(stderr, "Failed to update the OLDPWD environment variable\n");
		return (0);
	}

	return (1);
}

/**
 * change_current_directory - Changes the current directory
 * to the specified path this call Abive.
 * @path: path to check
 * Return: void
 */
void change_current_directory(char *path)
{
	char *current_path = getcwd(NULL, 0), *absolute_path = NULL,
		 *previous_path, *last_slash;

	if (current_path == NULL)
	{
		perror("getcwd");
		return;
	}
	previous_path = current_path;
	if (path[0] == '/')
		absolute_path = _strdup(path);
	else
	{
		absolute_path = (char *)malloc(PATH_MAX * sizeof(char));
		if (absolute_path == NULL)
		{
			perror("malloc");
			return;
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
	if (!change_directory(absolute_path))
	{
		free(absolute_path);
		return;
	}
	if (!update_directory_env(absolute_path, previous_path))
		change_directory(previous_path);
	free(absolute_path);
	free(current_path);
}
