#include "shell.h"

/**
*full - The function full concatenates command to tokenized path so that
*the path returned by full can serve as an argument to execve system call.
*The function takes two arguments which are an array of strings TokPath and
*a single string TokUserInput which contains the command name.
*@TokPath: An array of strings.
*@TokUserInput: A string which contains the value in characters of the command
*Return: Returns an an array of string which contains the full path.
*/

char **full(char **TokPath, char *TokUserInput)
{
	int PathCount;
	int CountA;
	char **FullPath;

	for (PathCount = 0; TokPath[PathCount] != NULL; PathCount++)
	{
	}

	FullPath = malloc((PathCount + 1) * sizeof(char *));

	if (FullPath == NULL)
	{
	perror("malloc() failed to allocate memory for FullPath");
	exit(EXIT_FAILURE);
	}

	for (CountA = 0; CountA < PathCount; CountA++)
	{
		int PathLen = stringlen(TokPath[CountA]);
		int Len = (PathLen + stringlen(TokUserInput) + 1);

		FullPath[CountA] = malloc(Len * sizeof(char));

	if (FullPath[CountA] == NULL)
	{
		perror("malloc() failed to allocate memory for FullPath[]");
		exit(EXIT_FAILURE);
	}

		stringcpy(FullPath[CountA], TokPath[CountA]);
		stringcat(FullPath[CountA], "/");
		stringcat(FullPath[CountA], TokUserInput);
		FullPath[CountA][Len] = '\0';
	}

	FullPath[CountA] = NULL;
	return (FullPath);
}
