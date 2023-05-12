#include "shell.h"

/**
*get_user_input - This function takes no argument. It initializes
*a size_t and ssize_t variables which are used to store the number of
*characters the user inputed including the null terminator character and the
*maximum number of input that user input can hold.
*It then uses malloc to alloc memeory to store user_input.
*If malloc failed to allocate memeory for user_input we return NULL.
*Else we initializes user_input_length with the return value of getline
*Passing our user_input memory allocated by malloc as the first argument,
*The MAX_USER_INPUT as second argument, and the standard input file stream
*as the third argument.
*We check if getline was able to read input from the standard input file stream
*If it doesnt we free the memory allocated for user_input and
*return a NULL pointer
*Else we add a null terminator at after the last character in user_input.
*That will enable us to manipulate user_input as string since every string must
*be terminated by a null character.
*After doing that we go ahead and return user_input string.
*The user is responsible for freeing user_input after use in the main function
*Read more on getline() function to understand how this function works.
*Return: The function returns a pointer which contains the string
*the user inputed.
*/

char *get_user_input()
{
	size_t MAX_USER_INPUT = BUFFER_SIZE;
	ssize_t user_input_length;
	char *user_input = malloc(sizeof(char) * MAX_USER_INPUT);

	if (user_input == NULL)
	{
		return (NULL);
	}
	else
	{
		user_input_length = getline(&user_input, &MAX_USER_INPUT, stdin);
		if (user_input_length == -1)
		{
			free(user_input);
			return (NULL);
			if ((user_input[(user_input_length - 1)] == '\0') ||
			(user_input[user_input_length - 1] == EOF))
			user_input[(user_input_length - 1)] = '\0';
		}
	}
	return (user_input);
}
