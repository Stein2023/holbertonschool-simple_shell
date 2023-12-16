# <h1 align="center"> A simple Shell </h1> 

The shell is a program that provides an interface between the user and the operating system.\
It allows users to interact with the system by typing commands and executing them.\
The shell works by prompting users for input, interpreting their input,\
and then handling output from the underlying operating system.

## [Header File - main.h]()

Header file that contains function prototypes and macro definitions.

It includes libraries such as string.h, stdio.h, stddef.h, fcntl.h,\
stdlib.h, unistd.h, sys/stat.h, sys/types.h, and sys/wait.h.\
The extern char **environ; is an external variable environ\
which is used to access the environment variables of the current process.

Lastly, it contains the function prototypes read_line, tokenize_line,\
exit_builtin, handle_env, execom, nonInteractive, and interactive,\
which are used in the implementation of the shell program.
