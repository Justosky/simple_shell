#include "shell.h"

/**
*stringcpy - A function that copies StringSource into StringDest. It
*returns StringDest which contains the copied string. It declares
*a variable CountA which will be use to iterate over the StringDest
*StringSource strings. Inside the loop it copies every character
*of StringSource into StringDest. Outside the loop it terminates
*the StringDest string properly by adding a null byte after the last
*character in the string
*@StringDest: The pointer that will contain the copied string
*@StringSource: The pointer which contains the string that is
*to be copied into StringDest.
*Return: Returns StringDest which is the copied string.
*/

char *stringcpy(char *StringDest, char *StringSource)
{
	int CountA;

	for (CountA = 0; StringSource[CountA] != '\0'; CountA++)
	{
		StringDest[CountA] = StringSource[CountA];
	}
	StringDest[CountA] = '\0';
	return (StringDest);
}
