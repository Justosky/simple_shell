#include "shell.h"

/**
*free_string_arrays - Frees the memory allocated for an array of strings.
*@StringArray: The array of string to be freed.
**/

void free_string_arrays(char **StringArray)
{
	int count;

	for (count = 0; StringArray[count] != NULL; count++)
	{
		free(StringArray[count]);
	}
	free(StringArray);
}
