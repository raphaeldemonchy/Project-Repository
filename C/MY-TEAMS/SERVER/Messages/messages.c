/*
** EPITECH PROJECT, 2022
** myTeams
** File description:
** messages.c
*/

#include "messages.h"

char* time_to_string(time_t time)
{
    static char buf[20];
    struct tm* tm_info = localtime(&time);
    strftime(buf, 20, "%Y-%m-%d %H:%M:%S", tm_info);
    return buf;
}

time_t string_to_time(char *string)
{
    time_t time;
    struct tm* tm_info = malloc(sizeof(struct tm));
    sscanf(string, "%d-%d-%d %d:%d:%d", &tm_info->tm_year, &tm_info->tm_mon,
    &tm_info->tm_mday, &tm_info->tm_hour, &tm_info->tm_min, &tm_info->tm_sec);
    tm_info->tm_year -= 1900;
    tm_info->tm_mon -= 1;
    time = mktime(tm_info);
    return time;
}

void add_already_saved_msg(message **messages, char **messages_tab)
{
    for (int i = 0, a = 0; messages_tab[i] != NULL; i++) {
        char *line = strtok(messages_tab[i], "/");
        messages[i] = malloc(sizeof(message));
        while (line != NULL && a < 4) {
            switch (a) {
                case 0: messages[i]->author_uuid = strdup(line); break;
                case 1: messages[i]->dest_uuid = strdup(line); break;
                case 2: messages[i]->content = strdup(line); break;
                case 3: messages[i]->message_times =
                    string_to_time(line); break;
            }
            line = strtok(NULL, "/");
            a++;
        }
        a = 0;
    }
}
