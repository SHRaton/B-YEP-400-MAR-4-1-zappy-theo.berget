/*
** EPITECH PROJECT, 2024
** B-YEP-400-MAR-4-1-zappy-theo.berget
** File description:
** look
*/

#include "../../include/my.h"

void look(server_t *s)
{
    char *sending = malloc(sizeof(char) * 1024);

    if (strcmp(s->server_data->command[0], "Look") == 0) {
        strcpy(sending, "[");
        // while (s->server_data->map_content[] != NULL) {

        // }
        strcpy(sending, "]");
        send_and_print(s, sending, s->server_net->current->socket);
        s->server_data->isCommand = 1;
    }
}
