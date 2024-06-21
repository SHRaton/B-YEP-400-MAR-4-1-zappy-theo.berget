/*
** EPITECH PROJECT, 2024
** B-YEP-400-MAR-4-1-zappy-theo.berget
** File description:
** take
*/

#include "../../include/my.h"

void take(server_t *s)
{
    if (strcmp(s->server_data->command[0], "Take") == 0) {
        send_and_print(s, "ok\n", s->server_net->current->socket);
        s->server_data->isCommand = 1;
    }
}
