#ifndef shell_h
#define shell_h
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <sys/wait.h>
#define BUFFER_SIZE 1024

int stringcmp(char *StringA, char *StringB, int a);
char *get_user_input();
char **tokenize(char *user_input, char *delimiter);
int stringlen(char *String);
void print(char *String);
char *get_path(char **envp);
int full_length(char **StringsA, char **StringsB);
char *stringdup(char *StringToDup);
char *stringcat(char *CompleteString, char *StringToAdd);
char **full_path(char **tok_path, char **tok_user_input);
char **init_envp(char **envp);
char *stringcpy(char *StringDest, char *StringSource);
char **full(char **TokPath, char *TokUserInput);
int half_len(char **half);
void args(char **FullPath, char **TokUserInput, char **envp);
void free_string_arrays(char **StringArray);
void execute_with_path(char **FullPath, char **TokUserInput, char **envp);
void free_string(char *Input);

#endif /* End of shell_h */
