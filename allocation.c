#include "main_shell.h"

/**
 * reallocate_array - reallocates a pointer to double the space
 * @array: pointer to the old array
 * @current_size: pointer to the current number of elements in the old array
 *
 * Return: pointer to the new array
 */
char **reallocate_array(char **array, size_t *current_size)
{
	char **new_array;
	size_t i;

	new_array = malloc(sizeof(char *) * ((*current_size) + 10));
	if (new_array == NULL)
	{
		free(array);
		return (NULL);
	}
	for (i = 0; i < (*current_size); i++)
	{
		new_array[i] = array[i];
	}
	*current_size += 10;
	free(array);
	return (new_array);
}
