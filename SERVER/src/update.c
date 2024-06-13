/*
** EPITECH PROJECT, 2024
** B-YEP-400-MAR-4-1-zappy-theo.berget
** File description:
** update
*/

#include "../include/my.h"

int update_nb_client(server_t *s, int add)
{
    int i = 0;
    char left[1024];
    char right[1024];
    char *tmp;
    char *new_string = malloc(sizeof(char) * 1024);
    strcpy(new_string, "");
    int nb = 0;
    while (s->server_data->teams[i] != NULL) {
        tmp = strdup(s->server_data->teams[i]);
        strcpy(left, "");
        strcpy(right, "");
        char *delim = strchr(tmp, ':');
        if (delim != NULL) {
            strncpy(left, tmp, delim - tmp);
            left[delim - tmp] = '\0';
            strncpy(right, delim + 1, strlen(delim + 1));
            right[strlen(delim + 1)] = '\0';
        }
        strcat(new_string, left);
        strcat(new_string, ":");
        nb = atoi(right);
        if (nb + add < 0) {
            free(tmp);
            return (84);
        }
        nb += add;
        strcat(new_string, int_to_str(nb));
        strcpy(s->server_data->teams[i], new_string);
        strcpy(new_string, "");
        free(tmp);
        i++;
    }
    dprintf(1, "(%s\n%s)\n", s->server_data->teams[0], s->server_data->teams[1]);
    return (0);
}
