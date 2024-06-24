/*
** EPITECH PROJECT, 2024
** B-YEP-400-MAR-4-1-zappy-theo.berget
** File description:
** bct
*/

#include "../../include/my.h"

void bct(server_t *s)
{
    char *sending = malloc(sizeof(char) * 1024);
    if (sending == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    if (strcmp(s->server_data->command[0], "bct") == 0) {
        send_and_print(s, sending, s->server_net->current->socket);
        s->server_data->isCommand = 1;
    }
    free(sending);
}
