#include "shell.h"

/**
*free_string - frees memory of a string allocated dynamically/
*@Input: The string to be freed
*/

void free_string(char *Input)
{
	if (Input != NULL)
	free(Input);
}
