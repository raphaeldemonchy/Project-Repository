/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include "../include/mysh.h"

int charge_buffer(data_s *data)
{
    size_t size = 2048;
    if (getline(&data->buffer, &size, stdin) > 0)
        return 0;
    else
        return 1;
    return 0;
}

int check_cmd(data_s *data, char **env)
{
    int a = 0;
    get_path(env, data);
    while (data->path[a] != 0) {
        data->path[a] = my_strcat(data->path[a], data->parsed_cmd[0], '/');
        if (access(data->path[a], F_OK) == 0
        && access(data->path[a], X_OK) == 0) {
            my_exec(env, data, data->path[a]);
            return 0;
        }
        a++;
    }
    return 1;
}

int my_arguments(data_s *data, char **env)
{
    if (my_strcmp(data->parsed_cmd[0], "cd") == 0) {
        builtin_cd(data, env);
        return (0);
    }
    if (my_strcmp(data->parsed_cmd[0], "setenv") == 0) {
        return (0);
    }
    if (my_strcmp(data->parsed_cmd[0], "env") == 0) {
        for (int i = 0; env[i] != 0; i += 1)
            my_putstr(env[i]), my_putchar('\n');
        return (0);
    }
    if (my_strcmp(data->parsed_cmd[0], "unsetenv") == 0) {
        return (0);
    }
    if (my_strcmp(data->parsed_cmd[0], EXIT) == 0) {
        write(0, "exit\n", 5);
        exit(0);
    }
    return (1);
}

int shell(data_s *data, char **env)
{
    if (data->buffer == NULL)
        return ERROR;
    prompter(1);
    int ret;
    while (charge_buffer(data) == 0) {
        data->buffer = parse_buffer(data->buffer);
        data->parsed_cmd = my_str_to_word_custom(data->buffer, ' ');
        ret = my_arguments(data, env);
        if (ret != 0) {
            if (check_cmd(data, env) == 1) {
                disp_cmd_nf(data);
            }
        }
        prompter(1);
    }
    return 0;
}

int main(int ac, char **av, char **env)
{
    data_s *data = malloc(sizeof(data_s));

    if (ac != 1 || av[1] != NULL)
        return ERROR;
    init_data(data, ac, env);
    if (shell(data, env) == 84)
        return ERROR;
    prompter(2);
    free(data->buffer);
    return 0;

}
