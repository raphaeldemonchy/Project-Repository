/*
** EPITECH PROJECT, 2023
** utils
** File description:
** utils
*/

#include "../client.h"

char *remove_quote(char *string)
{
    int i = 0;
    int j = 0;
    char *parsed_error_buffer = malloc(sizeof(char) * 1024);
    while (string[i] != '\0') {
        if (string[i] != '\"') {
            parsed_error_buffer[j] = string[i];
            j++;
        }
        i++;
    }
    return (parsed_error_buffer);
}

int is_alphanumeric(char *str)
{
    while (*str) {
        if (!isalnum(*str)) {
            return 1;
        }
        str++;
    }
    return 0;
}

int check_quote(char *arg)
{
    if (arg[0] != '\"' && strlen(arg) - 1 != '\"') {
        return (1);
    }
    return 0;

}
