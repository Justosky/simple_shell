#include "shell.h"

/**
*stringcmp - Similar to the standard library function strcmp. This function
*Takes two char pointers StringA and StringB which contains the strings that
*we want to compare. It uses a for loop to check if StringA and StringB at
*same index are not equal to null character. If one of the strings reaches
*the null terminator and the other has not the statement evaluate to false,
*If both of them reaches the null terminator at same index the statement
*evaluate to false too. After coming out of the loop.
*we check at the current index of the two strings if they both contain null.
*if so we return 0. Indicating that the two strings are equal.
*Else we will return the difference between the ASCII value of StringA and
*StringB, Which will always be a non zero number.
*@StringA: The first string to be compared with another string.
*@StringB: The second string to be compared with the first string.
*@a: Limit of the index at which we want to compare both strings.
*Return: Returns 0 if StringA and StringB are exactly equal.
*else will return the difference between the ASCII value for Strings A and B.
*/

int stringcmp(char *StringA, char *StringB, int a)
{
	int count;

	for (count = 0; (count < a) && (StringA[count] != '\0') &&
	(StringB[count] != '\0'); count++)
	{
		if (StringA[count] != StringB[count])
		return (StringA[count] - StringB[count]);
	}
	if ((StringA[count] == '\0') && (StringB[count] == '\0'))
	{
		return (0);
	}
	else
	{
		return (StringA[count] - StringB[count]);
	}
}
