#include "shell.h"

void args(char **FullPath, char **TokUserInput, char **envp)
{
    int a, b, c, lena;
    char **args;
	pid_t PID;

    for (a = 0; TokUserInput[a] != NULL; a++)
    {
    }

    args = malloc(sizeof(char *) * (a + 1));
    if (args == NULL)
    {
        perror("malloc() failed to allocate memory for args");
        exit(EXIT_FAILURE);
    }

    for (b = 0; FullPath[b] != NULL; b++)
    {
        if (access(FullPath[b], X_OK) == 0)
        {
            lena = stringlen(FullPath[b]);
            lena = lena + 1;
            args[0] = malloc(sizeof(char) * lena);
            if (args[0] == NULL)
            {
                perror("malloc() failed to allocate memory for args[0]");
                exit(EXIT_FAILURE);
            }
            stringcpy(args[0], FullPath[b]);
            args[0][lena - 1] = '\0';

            for (c = 0; TokUserInput[c + 1] != NULL; c++)
            {
                lena = stringlen(TokUserInput[c + 1]);
                lena = lena + 1;
                args[c + 1] = malloc(sizeof(char) * lena);
                if (args[c + 1] == NULL)
                {
                    perror("malloc() failed to allocate memory for args[c + 1]");
                    exit(EXIT_FAILURE);
                }
                stringcpy(args[c + 1], TokUserInput[c + 1]);
                args[c + 1][lena - 1] = '\0';
            }
            args[c + 1] = NULL;
        }
		execve(FullPath[b], args, envp);	
    }
}

