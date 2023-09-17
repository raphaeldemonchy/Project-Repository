/*
** EPITECH PROJECT, 2022
** mysh
** File description:
** mysh
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <dirent.h>

#ifndef mysh
#define mysh

///***************/
/// DATA STRUCT //
/***************/
typedef struct data_s {
    int total;
    int tmp_ac;
    char *buffer;
    char *ls_path;
    char **path;
    char **parsed_cmd;
    char *olw_pwd;
}data_s;

///****************************/
/// STR_TO_WORD_ARRAY CUSTOM //
/****************************/

typedef struct l_list
{
    int x;
    int y;
    int col;
}l_list;

///*********************/
///DEFINE MACRO COLORS//
/*********************/

#define RES "\e[0;0m"
#define RED "\e[3;1;5;31m"
#define BLUE "\e[1;34m"
#define GREEN "\e[1;32m"
#define YELLOW "\e[1;33m"

///*********************/
///DEFINE MACRO UTILS //
/*********************/

#define ERROR 84
#define BIN "/bin/"
#define EXIT "exit"
#define FORK "fork"
#define PATH "PATH="
#define S "S͍ͅH͍ͅE͍ͅL͍ͅL͍ͅ"
#define ENDSHELL YELLOW"\n⦕"RED"𝗦𝗛𝗘𝗟𝗟 𝗢𝗙𝗙"RES YELLOW"⦖\n"GREEN"→ "RES
#define PROMPT BLUE"⚝ "YELLOW"["RED S RES YELLOW"]"BLUE"⚝ "GREEN"→ "RES

///**************/
/// LIB CUSTOM //
/**************/
char **my_str_to_word_custom(char *str, char end);
char **my_str_to_word_v2(char *str, char end);
int my_show_word_array(char **tab);
char **my_str_to_word_array(data_s *stocker, char **env);

///*******/
/// LIB //
/*******/

int my_strlen(char const *str);
void my_putchar(char c);
int my_strcmp(char *s1, char *s2);
int my_strcmp_2(char *str1, char *str2);
char *my_strcat2(char *dest, char const *src);
char *my_strdup(char *str);
char *my_strdup2(char *str);
char *my_strdup3(char *str, int j);
char *my_strcat(char *dest, char *src, char c);
void my_putstr(char const *str);

///********/
/// MAIN //
/********/

int charge_buffer(data_s *data);
int check_cmd(data_s *data, char **env);
int shell(data_s *data, char **env);

///**************/
/// SHELL FUNC //
/**************/

char **refresh_pwd(char **env);
char *refresh_oldpwd(char **env);

void init_data(data_s *stocker, int ac, char **env);
void my_exec(char **env, data_s *data, char *buffer);
int check_cmd(data_s *data, char **env);
char *parse_buffer(char *buffer);
int builtin_cd(data_s *data, char **env);
void cd_home(data_s *data, char **env);

///*********/
/// UTILS //
/*********/

int count_bin(char **env);
char *parse_space(char *buffer);
void get_path(char **env, data_s *data);
void disp_cmd_nf(data_s *data);
void prompter(int turn);

#endif
