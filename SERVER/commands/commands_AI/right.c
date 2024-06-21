/*
** EPITECH PROJECT, 2024
** B-YEP-400-MAR-4-1-zappy-theo.berget
** File description:
** right
*/

#include "../../include/my.h"

void right(server_t *s)
{
    if (strcmp(s->server_data->command[0], "Right") == 0) {
        if (s->server_net->current->orientation == 1) {
            s->server_net->current->orientation = 2;
        } else if (s->server_net->current->orientation == 2) {
            s->server_net->current->orientation = 3;
        } else if (s->server_net->current->orientation == 3) {
            s->server_net->current->orientation = 4;
        } else if (s->server_net->current->orientation == 4) {
            s->server_net->current->orientation = 1;
        }
        s->server_data->isCommand = 1;
    }
}
