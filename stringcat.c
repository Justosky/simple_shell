#include "shell.h"

/**
*stringcat - This function concatenates two strings. It takes two character
*pointers CompleteString and StringToAdd as arguments. It initializes two
*integer variables countA and countB which will be used to set a
*loop condition. In the first loop, the function is trying to identify
*the position of the NULL character in CompleteString which
*is the end of the string.
*CountA is used to keep track of the index of NULL
*character in Complete String. In the second for loop, the function
*Copies the first character in StringToAdd to the position of the last
*character in the CompleteString perfectly replacing the NULL byte.
*CountA is incremented and CountB is incremented to Copy the rest characters
*from StringToAdd into CompleteString. Outside The loop CompleteString is
*properly terminated. And CompleteString is now returned.
*It copies the content of StringToAdd to the end of the last character
*in CompleteString untill it meets the null byte in StringToAdd.
*It terminates the CompleteString properly by adding a NULL byte to the end.
*It then returns CompleteString which is our concatenated string.
*@CompleteString: The destination string
*@StringToAdd: The destination string
*Return: Returns a pointer which contains the concatenate of CompleteString
*and StringToAdd.
*/

char *stringcat(char *CompleteString, char *StringToAdd)
{
	int CountA, CountB;

	for (CountA = 0; CompleteString[CountA] != '\0'; CountA++)
	{
	}

	for (CountB = 0; StringToAdd[CountB] != '\0'; CountB++)
	{
		CompleteString[CountA++] = StringToAdd[CountB];
	}
	CompleteString[CountA] = '\0';
	return (CompleteString);
}
