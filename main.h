#ifndef MAIN_H
#define MAIN_H

#include <string.h>
#include <stdio.h>
#include <stddef.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>


extern char **environ;
void freedom(char **array, char *name);
void read_line(char **line, size_t *line_size, ssize_t *read);
int tokenize_line(char *line, char **array);
void exit_builtin(void);
void handle_env(void);
void execom(char *command, char *args[]);
void nonInteractive(void);
char *checkpathfile(char *pithline, char *command);
char *pathchecksource(char **env);
void interactive(void);
void builtcheck(char *command);
void showerror(char *string);
int iswhite(const char *str);
void freestring(char * string, char *name);

#endif
