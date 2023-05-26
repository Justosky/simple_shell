#include "shell.h"

/**
*execute_with_path - Executes a command with FullPath
*@FullPath: Tokenized path with command concatenated to it
*@TokUserInput: Tokenized user input
*@envp: Environmental variables
*/

void execute_with_path(char **FullPath, char **TokUserInput, char **envp)
{
		int CountB = half_len(FullPath), CountA;
		pid_t PID;

		for (CountA = 0; (CountA < CountB) && access(FullPath[CountA], X_OK)
		!= 0; CountA++)
		{}
			if (access(FullPath[CountA], X_OK) == 0)
			{
				PID = fork();
				if (PID == 0)
				{
					execve(FullPath[CountA], TokUserInput, envp);
				}
				else if (PID < 0)
				{
					perror("fork() failed to create a child process");
				}
				else
				{
					wait(NULL);
				}
			}

}
