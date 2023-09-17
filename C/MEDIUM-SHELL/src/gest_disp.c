/*
** EPITECH PROJECT, 2022
** gest_disp
** File description:
** gest_disp
*/

#include "../include/mysh.h"

void prompter(int turn)
{
    char *line = YELLOW"⸻⸻⸻⸻⸻⸻⸻⸻⸻\n";

    if (turn == 1) {
        write(0, line, my_strlen(line));
        write(0, PROMPT, my_strlen(PROMPT));
    }
    else if (turn == 2) {
        write(0, ENDSHELL, my_strlen(ENDSHELL));
    }
}

void disp_cmd_nf(data_s *data)
{
    write(0, "command not found: ", 19);
    write(0, data->buffer, my_strlen(data->buffer)+1);
    write(0, "\n", 1);
}
