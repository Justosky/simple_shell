#include "shell.h"

/**
*print - This function is similar to the standard library function printf
*but it does not handle the case switches. It prints a string to the
*standard output. It initializes a an interger variable BytesToWrite
*with the return value of stringlen when String is passed to it as
*an argument. It initializes an ssize_t variable TotalBytesWritten
*with the return value of write system call when STDOUT_FILENO, String
*BytesToWrite are passed to it as first, second and third arguments
*respectively. It Checks if write fails and print an error message
*accordingly and. Else it checks if there's an incomplete write and
*prints an error message accordingly. Else The function writes to
*the standard output the content of the String.
*@String: A pointer which contains the string that is to be printed.
*/

void print(char *String)
{
	int BytesToWrite = stringlen(String);
	ssize_t TotalBytesWritten = write(STDOUT_FILENO, String, BytesToWrite);

	if (TotalBytesWritten == -1)
	{
		perror("Write() failed to write to the standard output");
		return;

		if (TotalBytesWritten < BytesToWrite)
		{
			perror("write() was unable to write all characters to standard output");
			return;
		}
	}
}
