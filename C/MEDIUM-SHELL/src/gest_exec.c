/*
** EPITECH PROJECT, 2022
** gest_exec
** File description:
** gest_exec
*/

#include "../include/mysh.h"
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

void my_exec(char **env, data_s *data, char *buffer)
{
    int sig = 0;
    pid_t pid = fork();

    if (pid == 0) {
        execve(buffer, data->parsed_cmd, env);
        exit(0);
    } else {
        waitpid(pid, &sig, 0);
        return;
    }
}
