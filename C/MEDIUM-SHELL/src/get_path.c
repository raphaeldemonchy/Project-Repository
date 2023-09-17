/*
** EPITECH PROJECT, 2022
** get_path
** File description:
** get_path
*/

#include "../include/mysh.h"

void get_path(char **env, data_s *data)
{
    int a = 0;

    while (env[a] != 0) {
        if (my_strcmp(PATH, env[a]) == 0)
            data->path = my_str_to_word_v2(env[a], ':');
        a++;
    }
}
