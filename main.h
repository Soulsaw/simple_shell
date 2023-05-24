#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
int exit_cmd(char *cmd);
void execute_process(pid_t *pid, char *argv[], char *name);
int env_cmd(char *cmd);
void _env(char **env);
#endif /* MAIN_H */
