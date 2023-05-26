#include "shell.h"

/**
*stringlen - stringlen function computes the length of a string.
*It takes a character pointer as an argument. It initializes an
*integer variable count. It checks if string is a NULL pointer and
*prints an error message and return (count - 1) which is same as -1
*Else it checks if String at an index of count contains the null character
*it increments count and the loop continues till String at an index of count
*becomes NULL. When the loop breaks it returns the current value of count
*which is the total number of characters within the string excluding the
*NULL byte.
*@String: The string that it's length is to be calculated.
*Return: The function returns count on success or (count - 1) on failure.
*/

int stringlen(char *String)
{
	int count = 0;

	if (String == NULL)
	{
		perror("Error encountered while calculating the lenght of an empty string");
		return (count - 1);
	}
	else
	{
		for (count = 0; String[count] != '\0'; count++)
		{	}
	return (count);
	}
}

