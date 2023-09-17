/*
** EPITECH PROJECT, 2022
** init_data
** File description:
** init_data
*/

#include "../include/mysh.h"

void init_data(data_s *data, int ac, char **env)
{
    data->tmp_ac = ac;
    data->olw_pwd = refresh_oldpwd(env);
    data->buffer = (char *)malloc(sizeof(char));
    data->ls_path = my_strdup(BIN);
    data->parsed_cmd = malloc(sizeof(char *) * 4);
    data->total = count_bin(env);
}
