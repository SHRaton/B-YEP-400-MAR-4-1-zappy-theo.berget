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
        if (1) {
            send(s->server_net->current->socket, "ok\n", strlen("ok\n"), 0);
            print_send_to_client(s, "ok\n");
        } else {
            send(s->server_net->current->socket, "ko\n", strlen("ko\n"), 0);
            print_send_to_client(s, "ko\n");
        }
        s->server_data->isCommand = 1;
    }
}