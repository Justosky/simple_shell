#include "shell.h"

/**
*stringdup - Just like the standard library function strdub. This
*function takes a string StringToDup which is the string to be duplicated
*as the only argument. It returns a character pointer which contains the
*duplicated string. It initializes a variable length with the return value
*of stringlen when StringToDup is passed to it as the first argument plus one.
*The plus one will account for the space needed to store the end-of
*string character null. It dynamically allocates memory to store the
*duplicated string using previously gotten length multiplied by the size of
*a character. It checks if memory allocation failed and prints an error
*message and return NULL. Else it uses a for loop to copy the content of
*StringToDup which is the string to be duplicated into DupString which will
*become our duplicated string at same index untill StringToDup at a particular
*index contains the null byte which marks the end of the string. After coming
*out of the loop. It sets the last index of DupString to nullbyte properly
*terminating the string. It then returns the
*the duplicated string DupString.
*@StringToDup: The string that is to be duplicated.
*Return: On success it returns a pointer which contains the same of the string
*that we duplicated else it returns NULL to indicate an error.
*/

char *stringdup(char *StringToDup)
{
	int length =  1 + (stringlen(StringToDup)), count;
	char *DupString = malloc(length * sizeof(char));

	if (DupString == NULL)
	{
		perror("Malloc() failed to allocate memory to duplicate string");
		return (DupString);
	}
	else
	{
		for (count = 0; StringToDup[count] != '\0'; count++)
		{
			DupString[count] = StringToDup[count];
		}
	}
	DupString[count] = '\0';
	return (DupString);
}
