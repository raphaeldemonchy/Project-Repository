#include "../include/tetris.h"

char *my_fusion_str(char *src, char *src_2, char *src_3)
{
    int size = my_strlen(src) + my_strlen(src_2) + my_strlen(src_3);
    char *final_str = malloc(sizeof(char) * size + 1);
    int i = 0;
    if (src == NULL || src_2 == NULL)
        return NULL;
    for (; src[i] != '\0'; i += 1)
        final_str[i] = src[i];
    for (int j = 0; src_2[j] != '\0'; j += 1, i += 1)
        final_str[i] = src_2[j];
    for (int j = 0; src_3[j] != '\0'; i += 1, j += 1) {
        if (src_3[j] == '\n') {
            final_str[i] = '\0';
            break;
        }
        final_str[i] = src_3[j];
    }
    final_str[i] = '\0';
    return final_str;
}

void putlink(link_t *link)
{
    int i = 0;
    if (link == NULL)
    write(1, "NULL", 4);
    while (link != NULL) {
        write(1, link->file, strlen(link->file));
        link = link->next;
        if (link != NULL)
            write(1, "\n->\n", 4);
    }
}

char *my_add_name(char *name)
{
    int i = 0;
    while (name[i] != '.')
        i += 1;
    char *tmp = malloc(sizeof(char) * i + 1);
    i = 0;
    for (; name[i] != '.'; i += 1)
        tmp[i] = name[i];
    tmp[i] = '\0';
    return tmp;
}

link_t *new_cell(link_t *link_chain, char *src, char *name)
{
    link_t *test = malloc(sizeof(link_t));
    if (test == NULL)
        return NULL;
    test->file = my_strdup(src);
    test->name = my_add_name(name);
    test->next = NULL;
    if (link_chain == NULL) {
        link_chain = test;
        return link_chain;
    }
    link_t *tmp = link_chain;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = test;
    // free(test);
    // free(tmp);
    return link_chain;
}

char *open_file(char *pathfile)
{
    int FileDirectory = 0, size = 0;
    struct stat buf;
    char *buff = NULL;
    char *src = my_fusion_str("", "tetriminos/", pathfile);
    FileDirectory = open(src, O_RDONLY);
    fstat(FileDirectory, &buf);
    size = buf.st_size;
    buff = malloc(sizeof(char) * size + 10);
    read(FileDirectory, buff, size);
    buff[size] = '\0';
    if (buff == NULL)
        return NULL;
    close(FileDirectory);
    return buff;
}

char *my_strdup(char *str)
{
    int i = 0;
    for (; str[i]; i += 1);
    char *temp = malloc(sizeof(char) * i + 1);
    for (int i = 0; str[i]; i += 1)
        temp[i] = str[i];
    temp[i] = '\0';
    return temp;
}

char *my_parse_name(char *src)
{
    int i = 0;
    while (src[i] != '.')
        i += 1;
    char *tmp = malloc(sizeof(char) * 3);
    for (i = 0; src[i] != '.'; i += 1)
        tmp[i] = src[i];
    tmp[i] = '\0';
    return tmp;
}

int check_char_name(char c)
{
    if ((c < '0' || c > '9') && c != ' ' && c != '\n')
        return -1;
    return 1;
}

int check_fake(char *file)
{
    int space = 0;
    int i = 0;
    for (i = 0; file[i] != '\n'; i += 1) {
        if (file[i] == ' ')
            space += 1;
        if (check_char_name(file[i]) == -1)
            return -1;
    }
    if (space != 2)
        return -1;
    while (file[i] != '\0')
        switch (file[i]) {
            case ' ' :
                i += 1;
                break;
            case '*' :
                i += 1;
                break;
            case '\n' :
                i += 1;
                break;
            default :
                return -1;
        }
    return 0;
}

char **str_to_array(char *src, char **tab)
{
    int i = 0, j = 0, x = 0, y = 1, s = 0, tmp;
    for (; src[x] != '\n'; x += 1)
        if (src[x] == ' ')
            y += 1;
    tab = malloc(sizeof(char *) * y + 1);
    for (tmp = 0; tmp != y; tmp += 1)
        tab[tmp] = malloc(sizeof(char) * x + 1);
    while (src[s] != '\n') {
        if (src[s] == ' ') {
            tab[i][j] = '\0';
            i += 1, s += 1, j = 0;
        }
        tab[i][j] = src[s];
        j += 1, s += 1;
    }
    tab[i][j] = '\0';
    return tab;
}

void init_color_size(link_t *link)
{
    if (my_strcmp(link->file, "error") == 0)
        return;
    char *src = my_strdup(link->file);
    int i = 0;
    while (link->file[i] != '\n')
        i += 1;
    char **tab = str_to_array(link->file, tab);
    link->x = atoi(tab[0]);
    link->y = atoi(tab[1]);
    link->color = atoi(tab[2]);
    free(tab);
}


void add_color_size(link_t *link)
{
    while (link) {
        if (check_fake(link->file) == -1)
            link->file = my_strdup("error");
        init_color_size(link);
        link = link->next;
    }

}

link_t *charge_link_tetriminos(link_t *link)
{
    DIR *d;
    struct dirent *dir;
    FILE *file;
    char *buff;
    d = opendir("tetriminos");
    if (d) {
        while ((dir = readdir(d)) != NULL)
            if (dir->d_name[0] != '.') {
                buff = open_file(dir->d_name);
                link = new_cell(link, buff, dir->d_name);
                add_color_size(link);
            }
        closedir(d);
    }
    return link;
}
