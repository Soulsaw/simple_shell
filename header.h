#ifndef HEADER_H
#define HEADER_H
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <signal.h>

void printstr(char *str);
int _putchar(char c);
int strlenght(char *str);
char *strcpy_cpy(char *dest, char *src);
int getnbwordstr(char *str);
void freealloc(char **argv);
int strcmpstr(char *s1, char *s2);

char *getcommand(void);
int executecommand(char *name, char **env);
void execute(char *name, char **env);
void getcommandarg(char ***argv);

int foundcommand(char *cmd);
char *addpath(char *cmd);
void exit_func(int status);
void create_process(char ***argv, char *name, char **env);

void printenv(char **env);
#endif /** HEADER_H */
