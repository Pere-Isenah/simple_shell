#ifndef _SHELL_H_
#define _SHELL_H_

#include <string.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>

/* execute.c functions */
void execute(char **command, char *name, char **env, int cycles);

/* errors.c functions */
void error_messages(char *name, int cycles, char **command);

/* memory_handler.c functions */
void free_n_exit(char **command);
void free_all(char **command);

/* string_functions.c functions */
int _strcmp(char *string1, char *string2);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _atoi(char *s);
int _strlen(char *string);

/* environment.c functions */
void _printenv(char **env);
char **_getpath(char **env);

/* process.c functions */
int change_dir(const char *path);
void launch_subprocess(char **command, char *name, char **env, int cycles);

/* shell.c functions */
int main(int ac, char **av, char **env);

/* shell_run.c functions */
void tipresh_prompt(void);
void ctrl_c_handler(int signals);
void _EOF(char *buffer);
void exit_shell(char **command);

/* tokenizer.c functions */
char **tokenizer(char *buffer, const char *delim);


#endif
