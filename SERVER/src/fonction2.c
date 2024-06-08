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
