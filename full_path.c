#include "shell.h"


/**
*full_path - The function takes two arguments tok_path and tok_user_input,
*which are arrays of strings and concatenates all strings in tok_user_input
*to each string in tok_path and return a pointer array which contains the
*concatenates. It declares path_count, i, j, length, full_path_count,
*and user_input_count which will be used to store various counts and indices
*It counts the number of elements in tok_path and tok_user_input arrays
*by iterating through tok_path and tok_user_input until a NULL pointer
*is encountered. The count of tok_path elements is stored in path_count,
*and the count of tok_user_input elements is stored in user_input_count.
*The value of path_count is assigned to full_path_count.
*It allocates memory dynamically for full_path using malloc.
*The number of elements in full_path is full_path_count + 1. Plus one accounts
*for the NULL pointer. The size of each element in full_path is calculated
*using sizeof(char *). If malloc fails to allocate memory,
*an error message is printed using perror, and NULL is returned.
*A loop is used to iterate over each element in tok_path.
*The variable length is initialized to the length of the current
*tok_path[i] string plus 1 to account for the additional '/' character.
*Another loop is used to iterate over each element in tok_user_input
*to calculate the total length required for the concatenated string.
*Memory is allocated for full_path[i] using malloc with the
*calculated length. If malloc fails to allocate memory, an error
*message is printed, and NULL is returned.
*The stringcpy function is called to copy the contents of
*tok_path[i] into full_path[i]. The stringcat function is
*After copying tok_path[i] to full_path[i] using stringcpy,
*the '/' character is appended to full_path[i] using stringcat.
*Then, a loop is used to iterate over each element in tok_user_input.
*For each element, the current element is appended to full_path[i]
*using stringcat, followed by a space character.
*This loop concatenates all the elements of tok_user_input to
*full_path[i], separated by spaces.
*After the loop, full_path[full_path_count] is set to NULL.
*This marks the end of the full_path array of strings.
*Finally, the function returns the full_path array.
*@tok_path: A tokenized PATH. And first argument of the full_path
*function.
*@tok_user_input: A tokenized user input which is to be appended
*to the  to every string in tokenized path to form full_path.
*It is the second and last argument to the full_path function.
*Return: It returns an array of strings which contains the concatenates
*tok_path and tok_user_input.
*/
char **full_path(char **tok_path, char **tok_user_input)
{
    int path_count = 0;
    int i, j;
    int length;
    int full_path_count;
    int user_input_count = 0;
    char **full_path;

    while (tok_path[path_count] != NULL)
        path_count++;

    while (tok_user_input[user_input_count] != NULL)
        user_input_count++;

    full_path_count = path_count;

    full_path = malloc((full_path_count + 1) * sizeof(char *));

    if (full_path == NULL)
    {
        perror("Malloc() failed to allocate memory for full_path");
        return NULL;
    }
    else
    {
        for (i = 0; i < path_count; i++)
        {
            length = stringlen(tok_path[i]) + 1;

            for (j = 0; j < user_input_count; j++)
            {
                length = length + stringlen(tok_user_input[j]) + 1;
            }

            full_path[i] = malloc(length * sizeof(char));
            if (full_path[i] == NULL)
            {
                perror("Malloc() failed to allocate memory for concatenated string");
                return NULL;
            }

            stringcpy(full_path[i], tok_path[i]);
            stringcat(full_path[i], "/");

            for (j = 0; j < user_input_count; j++)
            {
                stringcat(full_path[i], tok_user_input[j]);
                if (j < user_input_count - 1)
                {
		    
                    stringcat(full_path[i], "");
                }	  
            }
            full_path[i][length - 2] = '\0';
        }
        full_path[full_path_count] = NULL;
        return full_path;
    }
}

