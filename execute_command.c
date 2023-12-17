#include "main.h"
/**
 * execom - Executes a command in a child process
 * @command: The command to be executed. It can be a full path to the
 * executable or just the command.
 * @args:array of arguments to be passed to the command.
 * @envp:array of strings that represent the environment for the new process.
 * Return: nothing.
 */
void execom(char *command, char *args[], char *envp[])
{
	char *func = "execute command";
	pid_t pid;
	char **env = environ, *path = NULL, *fullpath = NULL;
	struct stat filestat;
	int exectype = 0;
	
	if (strcmp(command, "exit") == 0)
	{
	printf("comparar %s = %s", command, "exit");
	freedom(args, func);
	exit(EXIT_SUCCESS);
	}
	builtcheck(command);
	if (stat(command, &filestat) == 0)
		exectype = 1;
	else
	{
		path = pathchecksource(env);
		if (path != NULL)
		{
			fullpath = checkpathfile(path, command);
			freestring(path, func);
			if (fullpath != NULL)
				exectype = 2;
	       	} 
	}
	if (exectype == 0)
	{
		printf("bash: %s: command not found\n", command);
		freestring(fullpath, func);
		return; }
	pid = fork();
	if (pid == 0)
	{
		if (exectype == 1)
		{
			if (execve(command, args, envp) == -1)
			{	
				freedom(args, func);
				freestring(fullpath, func);
				showerror("Execve Failure");
		       	}
		}
		else if (exectype == 2)
		{
			if (execve(fullpath, args, envp) == -1)
			{
				freedom(args, func);
				freestring(fullpath, func);
				showerror("Execve Failure");
			}
	       	}
	}
	else
	{
		if (waitpid(pid, NULL, 0) == -1)
		{
			freedom(args, func);
			freestring(fullpath, func);
			showerror("waitpid"); 
		}
		freestring(fullpath, func);
	}
}
