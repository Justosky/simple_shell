#ifndef shell_h
#define shell_h
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
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

#endif /* End of shell_h */
