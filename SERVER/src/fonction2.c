/*
** EPITECH PROJECT, 2024
** B-YEP-400-MAR-4-1-zappy-alexandre.vittenet
** File description:
** fonction2
*/

#include "../include/my.h"

// Fonction qui permet d'afficher un char **
void print_strstr(char **str)
{
    int z = 0;

    while (str[z] != NULL) {
        dprintf(1, "%s\n", str[z]);
        z++;
    }
}

// Fonction qui supprime tout les caractere défini en argument d'un char *
// et renvoie le nouveau char *
char *remove_cara(char *str, char c)
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
        if (str[z] != c) {
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
