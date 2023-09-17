/*
** EPITECH PROJECT, 2022
** builtin_cd
** File description:
** builtin_cd
*/

#include "../include/mysh.h"

int check_opendir(data_s *data)
{
	char *open = "opendir";
    if (opendir(data->parsed_cmd[1]) == NULL) {
        perror(open);
        return (1);
    }
    if (opendir(data->olw_pwd) == NULL) {
        perror(open);
        return (2);
        }
    return 0;
}

char **refresh_pwd(char **env)
{
    int y = 0;
    char *pwd = my_strdup2("PWD=");
    char *cwd = malloc(sizeof(char) * 4096);
    char *stk = malloc(sizeof(char) * 4069);
    for (; my_strcmp_2(pwd, env[y]) != 0; y++);
    stk = my_strdup2(pwd);
    stk = my_strcat2(stk, getcwd(cwd, 4096));
    env[y] = my_strdup2(stk);
    return (env);
}

char *refresh_oldpwd(char **env)
{
    int y = 0;
    char *old_pwd = my_strdup2("OLDPWD=");
    char *olwd = malloc(sizeof(char) * 4096);
    char *stk = malloc(sizeof(char) * 4096);
    for (; my_strcmp_2(old_pwd, env[y]) != 0; y++);
    stk = my_strdup2(old_pwd);
    stk = my_strcat2(stk, getcwd(olwd, 4096));
    char *ret = my_strdup2(env[y]);
    env[y] = my_strdup2(stk);
    ret = my_strdup3(ret, 7);
    return (ret);
}

void cd_home(data_s *data, char **env)
{
    int y = 0;
    char *ret;
    char *home = my_strdup2("HOME=");
    for (; my_strcmp_2(home, env[y]) != 0; y++);
    ret = my_strdup2(env[y]);
    ret = my_strdup3(ret, 5);
    if (my_strcmp_2(home, env[y]) == 0) {
        data->olw_pwd = refresh_oldpwd(env);
        chdir(ret);
        refresh_pwd(env);
    }
}

int builtin_cd(data_s *data, char **env)
{
    if (data->parsed_cmd[1] != NULL && data->parsed_cmd[1][0] != '-') {
        if (check_opendir(data) == 1)
            return (1);
        data->olw_pwd = refresh_oldpwd(env);
        chdir(data->parsed_cmd[1]);
        refresh_pwd(env);
        return (0);
    } else if (data->parsed_cmd[1] != NULL
    && data->parsed_cmd[1][0] == '-') {
        if (check_opendir(data) == 2)
                return 1;
        data->olw_pwd = refresh_oldpwd(env);
        chdir(data->olw_pwd);
        refresh_pwd(env);
        return (0);
    } else if (data->parsed_cmd[1] == NULL) {
            cd_home(data, env);
            return (0);
    }
    return 0;
}
