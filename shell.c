#include "shell.h"


int main(int argc, char **argv, char **envp)
{
	int CountA, CountB, CountC, CountD;
	char *Input;
	char **TokUserInput;
	char **FullPath;
	char *Path = get_path(envp);
	char **TokPath = tokenize(Path, ":");
	char **arg;
	for (;;)
	{
		print(" ($) ");
		Input = get_user_input();
		TokUserInput = tokenize(Input,"");
		FullPath = full(TokPath, TokUserInput[0]);
		printf("PATH IS %s\n", FullPath[1]);
		args(FullPath, TokUserInput, envp);
	}	
	for (CountB = 0; TokUserInput[CountB] != NULL; CountB++)
	{
		free(TokUserInput[CountB]);
	}
	for (CountB = 0; TokPath[CountB] != NULL; CountB++)
	{
		free(TokPath[CountB]);
	}
	for (CountB = 0; FullPath[CountB] != NULL; CountB++)
	{
		free(FullPath[CountB]);
	}
	free(Input);
	free(TokUserInput);
	free(TokPath);
	free(FullPath);
}	
