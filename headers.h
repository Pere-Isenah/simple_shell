#ifndef _HEADERS_H_
#define _HEADERS_H_

/*   Libraries. */

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/*   Our functions. */

char **space_organizer(char *, const char *, int len, int *strcount);
int one_finxer(char **arguments, char **path, int size0, int size1, int *);
int decision_taker(char **arguments, int size, char **_env, int *wstatus);
int executor(char **aop, const char *path, int size);
void printenv(char **envp);
void a_liberator(char **aop, int size);
void path_finder(char **aop, int size, char **_env, int *wstatus);

/*   Generic functions. */

char *_strncpy(char *dest, char *src, int n);
int _strlen(char *str);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);

#endif /* _HEADERS_H_ */
