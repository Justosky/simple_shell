#include "shell.h"

/**
*tok_user_input - This function takes a character pointer
*which contains the string that we want to tokenize as an argument.
*It initializes a character constant pointer
*character pointer delimiter with a string literal which will be used
*to split or tokenize the user_input string. It initializes two integer
*variables NumOfTok and MaxNumOfTok with 0 and BUFFER_SIZE respectively.
*BUFFER_SIZE is a macro defined in the shell.h file
*And it's value is 1024. It initializes another character pointer Token
*and sets it to NULL. It will be used to store the tokens temporarily
*as strtok returns them. It dynamically allocates memory for Tokens which
*is an array of pointers that will be used to store each of the token.
*Each of the token will be stored in a pointer within the array of
*pointers. It checks if malloc failed to allocate memory successfully
*and we print an error message using perror. Else it assign Token with the
*return value of strtok when given user_input and delimiter pointers
*as argument one and two respectively. It checks if strtok failed and
*frees the Tokens memory
*allocated by malloc and returns NULL.
*Else it checks if NumOfTok is equal to MaxNumOfTok and reallocates memory for
*Tokens to handle the new characters It checks if reallocation of memory failed
*and frees the memory held by Token and return NULL.
*Else it stores the first Token at the 0th index of Tokens double pointer
*It updates Token to hold the memory address of the next token in the
*user_input string By passing it the return value of strtok when NULL and
*delimiter pointer is passed to it as first and
*second argument. Finally the function returns the tokenized user_input.
*The user of this function will be responsible in freeing Tokens in
*the main function. To understand clearly how this function works read
*about strtok() function.
*@user_input: A pointer which holds the memory address of the string 
*that we want to tokenize.
*Return: This function returns a double pointer which contains
*the tokenized strings.
*/

char **tokenize(char *user_input, char *delimiter)
{
    int NumOfTok = 0, MaxNumOfTok = BUFFER_SIZE;
    char *Token = NULL;
    char **Tokens = malloc(sizeof(char *) * (MaxNumOfTok + 1));

    if (Tokens == NULL)
    {
        perror("Malloc failed to allocate memory for storing tokens");
        return NULL;
    }
    else
    {
        Token = strtok(user_input, delimiter);

        if (Token == NULL)
        {
            perror("Strtok failed to tokenize user input");
        }
        else
        {
            while (Token != NULL)
            {
                if (NumOfTok == MaxNumOfTok)
                {
                    MaxNumOfTok = MaxNumOfTok * 2;
                    Tokens = realloc(Tokens, (MaxNumOfTok + 1) * sizeof(char *));
                    if (Tokens == NULL)
                    {
                        perror("Realloc failed to reallocate memory for storing token");
                        free(Tokens);
                        return (NULL);
                    }
                }
                Tokens[NumOfTok] = malloc(stringlen(Token));
                if (Tokens[NumOfTok] == NULL)
                {
                    perror("Malloc failed to allocate memory for token");
                    free(Tokens);
                    return NULL;
                }
                stringcpy(Tokens[NumOfTok], Token);
                NumOfTok++;
                Token = strtok(NULL, delimiter);
            }
        }
    }
    Tokens[NumOfTok] = NULL;
    return Tokens;
}

