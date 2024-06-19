/*
** EPITECH PROJECT, 2024
** B-YEP-400-MAR-4-1-zappy-theo.berget
** File description:
** forward
*/

#include "../../include/my.h"

void forward(server_t *s)
{
    if (strcmp(s->server_data->command[0], "Forward") == 0) {
        if (s->server_net->current->orientation == 1) {
            if (s->server_net->current->pos_y - 1 >= 1) {
                s->server_net->current->pos_y -= 1;
                send_and_print(s, "ok\n", s->server_net->current->socket);
            } else {
                send_and_print(s, "ko\n", s->server_net->current->socket);
            }
        }
        if (s->server_net->current->orientation == 2) {
            if (s->server_net->current->pos_x + 1 <= s->arg->_width - 1) {
                s->server_net->current->pos_x += 1;
                send_and_print(s, "ok\n", s->server_net->current->socket);
            } else {
                send_and_print(s, "ko\n", s->server_net->current->socket);
            }
        }
        if (s->server_net->current->orientation == 3) {
            if (s->server_net->current->pos_y + 1 <= s->arg->_height - 1) {
                s->server_net->current->pos_y += 1;
                send_and_print(s, "ok\n", s->server_net->current->socket);
            } else {
                send_and_print(s, "ko\n", s->server_net->current->socket);
            }
        }
        if (s->server_net->current->orientation == 4) {
            if (s->server_net->current->pos_x - 1 >= 1) {
                s->server_net->current->pos_x -= 1;
                send_and_print(s, "ok\n", s->server_net->current->socket);
            } else {
                send_and_print(s, "ko\n", s->server_net->current->socket);
            }
        }
        s->server_data->isCommand = 1;
    }
}
