/*
** EPITECH PROJECT, 2024
** B-YEP-400-MAR-4-1-zappy-theo.berget
** File description:
** pic
*/

#include "../../include/my.h"

void pic(server_t *s)
{
    char *sending = malloc(sizeof(char) * 1024);

    if (sending == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    if (strcmp(s->server_data->command[0], "pic") == 0) {
        send_and_print(s, sending, s->server_net->current->socket);
        s->server_data->isCommand = 1;
    }
    free(sending);
}
