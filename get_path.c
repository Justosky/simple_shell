#include "shell.h"

/**
* *get_path - This function gets the value of PATH environmental variable
*as it is on a user computer. It exlude this string "PATH=" from
*the value of path. The function initializes a character pointer
*path which we will use to store the value of PATH. It initializes
*an interger variable count. it checks if environmental variable
*double pointer is holding a valid memomory address. If it is not
*we print an error message and return NULL. Else we transverse the
*envp double pointer looking for an environmental variable which
*the first five characters matches the string "PATH=". When that
*environmental variable is found we start to copy the value
*of that environmental variable from the fifth character to another
*pointer path. The pointer path which now holds the value of the
*environmental variable PATH is returned within function.
*@envp: A double pointer which is the third argument of the main function.
*It holds the name of all environmental variables and it's value as it is
*on a user computer.
*Return: This function returns a pointer which contains the value of the
*environmental variable PATH on success else it returns a NULL pointer to
*indicate an error or failure.
*/

char *get_path(char **envp)
{
	char *path = NULL;
	int count;

	if (envp == NULL)
	{
		perror("envp failed to provide PATH");
		return (NULL);
	}
	else
	{
		for (count = 0; envp[count] != NULL; count++)
		{
			if ((stringcmp(envp[count], "PATH=", 4)) == 0)
			{
				path = envp[count] + 5;
				return (path);
			}
		}
	}
	return (NULL);
}
