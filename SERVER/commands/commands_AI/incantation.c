/*
** EPITECH PROJECT, 2024
** B-YEP-400-MAR-4-1-zappy-theo.berget
** File description:
** incantation
*/

#include "../../include/my.h"

void incantation(server_t *s)
{
    if (strcmp(s->server_data->command[0], "Incantation") == 0) {
        s->server_net->current->level += 1;
        dprintf(1, "\n\nLEVEL UP = (%d)\n\n", s->server_net->current->level);
        send_and_print(s, "ok\n", s->server_net->current->socket);
        s->server_data->isCommand = 1;
    }
}
