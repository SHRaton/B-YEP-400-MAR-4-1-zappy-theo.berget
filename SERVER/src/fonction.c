/*
** EPITECH PROJECT, 2024
** B-YEP-400-MAR-4-1-zappy-alexandre.vittenet
** File description:
** fonction
*/

#include "../include/my.h"

// Fonction qui retourn 0 si le char cara est contenu dans le char *str
// et 1 si ce n'es pas le cas
int is_contain(char *str, char cara)
{
    int z = 0;

    while (str[z] != '\0') {
        if (str[z] == cara) {
            return (0);
        }
        z++;
    }
    return (1);
}

// Fonction qui prends un char *str et un char tok et qui transforme la chaine
// de caractere str en un tableau char ** coupé en fonction de tok
char **str_to_word_array(char *str, char *tok)
{
    char *str_tmp = strdup(str);
    if (str_tmp == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    char **tmp_2 = malloc(sizeof(char *) * 1);
    if (tmp_2 == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    char **tab = malloc(sizeof(char *) * 4096);
    if (tab == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    char *tmp_1 = strtok(str_tmp, tok);
    int i = 0;

    if (str_tmp == NULL || strspn(str_tmp, " \t\r\n") == strlen(str_tmp) || tok == NULL) {
        tmp_2[0] = strdup("\r\n");
        return (tmp_2);
    }
    for (; tmp_1 != NULL; i++) {
        tab[i] = strdup(tmp_1);
        tmp_1 = strtok(NULL, tok);
    }
    tab[i] = NULL;
    return (tab);
}

// Fonction annexe de int_to_str qui permet de retourner caractere par
// caractere un char *
char *reverse(char *str)
{
    char tmp;
    char *src;
    char *dst;
    size_t len;

    if (str != NULL) {
        len = strlen(str);
    }
    if (len > 1 && str != NULL) {
        src = str;
        dst = src + len - 1;
        while (src < dst) {
            tmp = *src;
            *src++;
            *src = *dst;
            *dst--;
            *dst = tmp;
        }
    }
    return str;
}

// Fonction qui transforme un int en un char *
char *int_to_str(int num)
{
    int size = snprintf(NULL, 0, "%d", num);
    char *str = malloc(sizeof(char) * size + 1);
    if (str == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    snprintf(str, (size + 1), "%d", num);
    return str;
}

// Fonction qui supprime tout les guillemets d'un char * et renvoie le
// nouveau char *
char *removed_quote(char *str)
{
    char *tmp = malloc(sizeof(char) * 9888);
    if (tmp == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    int z = 0;
    int y = 0;

    strcpy(tmp, "");
    while (str[z] != '\0') {
        if (str[z] != '\"') {
            tmp[y] = str[z];
            y++;
        }
        z++;
    }
    tmp[y] = '\0';
    if (strcmp(tmp, "") == 0) {
        return (NULL);
    }
    return (tmp);
}
