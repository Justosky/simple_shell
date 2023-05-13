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

#endif /* End of shell_h */
