# <h1 align="center"> A simple Shell </h1> 

The shell is a program that provides an interface between\
the user and the operating system. It allows users to\
interact with the system by typing commands and executing them.\
The shell works by prompting users for input, interpreting their input,\
and then handling output from the underlying operating system.

Our shell handles the interactive and non-interactive modes.

- Compiled with:
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

- Clone it with
```
git clone https://github.com/Stein2023/holbertonschool-simple_shell.git
```
## [Header File - main.h]()

Header file that contains function prototypes, libraries and\
en external variable.

| Libraries |
| ---------- |
| <string.h> |
| <stdio.h> |
| <stddef.h> |
| <fcntl.h> |
| <stdlib.h> | 
| <unistd.h> | 
| <sys/stat.h> |
| <sys/types.h> |
| <sys/wait.h> |

The ```extern char **environ;``` is an external variable environ.\

| Function protoypes |
| ------------------ |
| void interactive(void); |
| void nonInteractive(void) |
| void execom(char *command, char *args[]); |
| void read_line(char **line, size_t *line_size, ssize_t *read) |
| int tokenize_line(char *line, char **array) |
| char *checkpathfile(char *pathline, char *command) |
| char *pathchecksource(char **env) |
| int iswhite(const char *str); |
| void freedom(char **array, char *name); |
| void freestring(char * string, char *name); |
| void showerror(char *string); |

## [simpleshell.c](https://github.com/Stein2023/holbertonschool-simple_shell/blob/master/simpleshell.c)

Function to call the different modes for the shell,\
**interactive** and **non-interactive**.

 ## [interactive.c](https://github.com/Stein2023/holbertonschool-simple_shell/blob/master/interactive.c)

It has the function named **interactive**. It is used to run an\
interactive shell. The function reads input from the user,\
tokenizes it, and executes the command. The function also checks\
if the input is empty or not. If the input is empty, it continues\
to the next iteration of the loop. If the input is not empty,\
it allocates memory for the tokens, tokenizes the input, executes\
the command, and frees the memory allocated for the tokens.

```
root@74be033d1686:/holbertonschool-simple_shell# ./hsh
$
$
$ ls
AUTHORS          env_builtin.c      freedom.c      main.h            read_line.c  simpleshell.c
builtcheck.c     execute_command.c  hsh            noninteractive.c  README.md    tokenize_line.c
checkpathfile.c  exit_builtin.c     interactive.c  pathcheck.c       showerror.c  whitespace.c
$ /bin/ls
AUTHORS          env_builtin.c      freedom.c      main.h            read_line.c  simpleshell.c
builtcheck.c     execute_command.c  hsh            noninteractive.c  README.md    tokenize_line.c
checkpathfile.c  exit_builtin.c     interactive.c  pathcheck.c       showerror.c  whitespace.c
$ echo "Hello there"
"Hello there"
$ exit
root@74be033d1686:/holbertonschool-simple_shell#
```
 ## [noninteractive.c](https://github.com/Stein2023/holbertonschool-simple_shell/blob/master/noninteractive.c)

The **nonInteractive** function is designed to execute commands\
in non-interactive mode. It reads input from the input,\
tokenizes it, and executes the command. The function uses\
several other functions (read_line, iswhite, freestring, malloc,\
tokenize_line, execom, freedom). The use of a while (1) loop tells\
that is made to run indefinitely until an exit condition is met,\
such as encountering a whitespace line or an error.

 ```
root@74be033d1686:/holbertonschool-simple_shell# $ echo "qwerty" | ./hs
bash: $: command not found
bash: ./hs: No such file or directory
root@74be033d1686:/holbertonschool-simple_shell# echo "/bin/ls" | ./hsh
AUTHORS          env_builtin.c      freedom.c      main.h            read_line.c  simpleshell.c
builtcheck.c     execute_command.c  hsh            noninteractive.c  README.md    tokenize_line.c
checkpathfile.c  exit_builtin.c     interactive.c  pathcheck.c       showerror.c  whitespace.c
root@74be033d1686:/holbertonschool-simple_shell# echo "/bin/ls
> /bin/ls
> /bin/ls" | ./hsh
AUTHORS          env_builtin.c      freedom.c      main.h            read_line.c  simpleshell.c
builtcheck.c     execute_command.c  hsh            noninteractive.c  README.md    tokenize_line.c
checkpathfile.c  exit_builtin.c     interactive.c  pathcheck.c       showerror.c  whitespace.c
AUTHORS          env_builtin.c      freedom.c      main.h            read_line.c  simpleshell.c
builtcheck.c     execute_command.c  hsh            noninteractive.c  README.md    tokenize_line.c
checkpathfile.c  exit_builtin.c     interactive.c  pathcheck.c       showerror.c  whitespace.c
AUTHORS          env_builtin.c      freedom.c      main.h            read_line.c  simpleshell.c
builtcheck.c     execute_command.c  hsh            noninteractive.c  README.md    tokenize_line.c
checkpathfile.c  exit_builtin.c     interactive.c  pathcheck.c       showerror.c  whitespace.c
root@74be033d1686:/holbertonschool-simple_shell# echo "         " | ./hsh
root@74be033d1686:/holbertonschool-simple_shell#
```
 ## [execute_command.c](https://github.com/Stein2023/holbertonschool-simple_shell/blob/master/execute_command.c)

The **execom** function in the code executes a command\
in a child process. It checks if the command exists as\
a file in the current directory or in any of the directories\
listed in the PATH environment variable. If it finds the command,\
it creates a new process using the fork function and executes\
the command using the execve function. If the command does not exist,\
it prints an error message and returns. The function waits for the child\
process to finish executing the command using the waitpid function.\
Finally, it frees the memory allocated for fullpath and returns.

 ## [read_line.c](https://github.com/Stein2023/holbertonschool-simple_shell/blob/master/read_line.c)

The **read_line** function reads a line of text from the\
standard inputand stores it in the memory location pointed\
to by line. It initializes line to NULL and line_size to 0.\
These are pointers to a pointer and a size_t variable,\
respectively, which will be used to store the input line and its size.\
The function calls the getline function to read a line from the\
standard input. If getline returns -1, it means there was an\
error or EOF was reached. If getline returns 1, it means only\
a newline character was read. In this case, the function prints\
a $ prompt. This function is useful for reading lines of input\
from the user in a command-line interface.

 ## [tokenize_line.c](https://github.com/Stein2023/holbertonschool-simple_shell/blob/master/tokenize_line.c)

The **tokenize_line** function splits a given line into\
tokens based on certain delimiters. It takes two parameters:\
a string line to be tokenized and an array array to store the tokens.\
The function returns the number of tokens found after splitting\
the line into substrings using the delimiters space (" “), tab\
(”\t"), and newline (“\n”). The last element of the array is set\
to NULL to indicate the end of the tokens.\
Finally, the function frees the memory used by the line.

 ## [checkpathfile.c](https://github.com/Stein2023/holbertonschool-simple_shell/blob/master/checkpathfile.c)

**checkpathfile** is a function that checks if a file\
corresponding to the command exists in the directories\
specified in the path string. If it finds such a file,\
it returns the full path to that file. If it doesn’t find\
the file, it returns NULL. It splits the path string into\
individual paths using the colon (“:”) as a delimiter and\
uses the stat function to get the status of the file at fullpath.\
If stat returns 0, it means the file exists, and the function\
returns fullpath. If the function has checked all paths and hasn’t\
found the file, it returns NULL. This function is useful for\
checking if a command exists in the directories specified in the path string.

 ## [pathcheck.c](https://github.com/Stein2023/holbertonschool-simple_shell/blob/master/pathcheck.c)

**pathchecksource** is a function which takes an array\
of strings as an argument, which represents the\
environment variables. It is made to find and return\
the value of the “PATH” environment variable. It uses\
a while loop to compare the current environment variable\
with the string “PATH=”. If they are equal, it duplicates\
the value of the “PATH” variable and assigns the duplicate\
to path. Finally, it returns path, which is either the value\
of the “PATH” variable or NULL. This function is useful for\
retrieving the value of the “PATH” environment variable, \
which is used by the shell to find executables.

## [whitespace.c](https://github.com/Stein2023/holbertonschool-simple_shell/blob/master/whitespace.c)

**iswhite** checks if a given string is composed\
entirely of whitespace characters. It returns 1 if\
the string is made up of only whitespace characters,\
and 0 otherwise. It uses the strspn function to check\
how many characters at the start of the string are part\
of the set of characters specified in the second argument.\
If this length is not equal to the length of the string,\
it means that the string contains characters other than the\
specified whitespace characters, and the function immediately\
returns 0. Otherwise, it returns 1. This function is useful for\
checking if a string is composed entirely of whitespace characters.

## [freedom.c](https://github.com/Stein2023/holbertonschool-simple_shell/blob/master/freedom.c)

**freedom** frees each element of an array and then\
frees the array itself. It takes two parameters: array,\
which is a pointer to a pointer to a character, and name,\
which is a pointer to a character. The function first\
checks if array is not NULL. If it is not, it then enters\
a while loop where it calls the freestring function for each\
element of the array until it encounters a NULL element.\
After the loop, it calls freestring one more time for the\
NULL element and then frees the array itself.\
Finally, it sets array to NULL.

**freestring** frees a string and then sets the string to NULL.\
It takes two parameters: string, which is a pointer to a character,\
and name, which is a pointer to a character.\
The function first checks if string is not NULL.\
If it is not, it then frees string and sets it to NULL.

## [showerror.c](https://github.com/Stein2023/holbertonschool-simple_shell/blob/master/showerror.c)

**showerror** is a function that shows an error\
message and exits the program. It takes a string\
as an argument and prints the string followed by a colon,\
a space, and then the current errno value.\
Finally, it exits the program with a failure status.\
This function is useful for handling errors.

### Flowchart

 <a href="https://ibb.co/Sms6K29"><img src="https://i.ibb.co/1Xv093w/Blank-diagram.jpg" alt="Blank-diagram" border="0"></a>
