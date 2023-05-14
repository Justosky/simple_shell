#include "shell.h"

/**
*stringcat - This function concatenates two strings. It takes two character
*pointers CompleteString and StringToAdd as arguments. It initializes two
*interger variables countA and countB which will be used to set a
*loop condition
*it initializes another interger variable count and assign it return value
*of stringlen when CompleteString is passed to it as an argument plus plus
*return value of stringlen when StringToAdd is passed to it as an argument.
*It initializes a character pointer FullPath which will be used to store the
*concatenated strings and allocates memeory to it dynamically using malloc.
*The size allocated with malloc is of size (length + 1) * sizeof (char). Plus
*one added to length accounts for the null byte.
*It checks if memeory allocation was successful else it prints an error message
*using perror and returns NULL. It copies all contents of CompleteString
*till into FullPath till it encounters the null byte in CompleteString
*It copies the content of StringToAdd to the end of the last character
*in FullPath untill it meets the null byte in StringToAdd.
*It terminates the FullPath String properly by adding a null byte to the end.
*It then returns FullPath which is our concatenated string.
*@CompleteString: The destination string
*@StringToAdd: The destination string
*Return: Returns a pointer which contains the concatenate of CompleteString
*and StringToAdd.
*and it is the responsibility of the engineer to free FullPath after use.
*/

char *stringcat(char *CompleteString, char *StringToAdd)
{
	int countA, countB;

	int length = (stringlen(CompleteString) + stringlen(StringToAdd));

	char *FullString = malloc((length + 1) * sizeof(char));

	if (FullString == NULL)
	{
		perror("Malloc() failed to allocate memory to concatenate strings");
		return (NULL);
	}

	for (countA = 0; CompleteString[countA] != '\0'; countA++)
	{
		FullString[countA] = CompleteString[countA];
	}
	for (countB = 0; StringToAdd[countB] != '\0'; countB++)
	{
		FullString[countA++] = StringToAdd[countB];
	}
	FullString[countA] = '\0';
	return (FullString);
}
