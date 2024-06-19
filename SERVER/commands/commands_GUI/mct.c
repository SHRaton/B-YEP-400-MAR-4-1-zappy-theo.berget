/*
** EPITECH PROJECT, 2024
** B-YEP-400-MAR-4-1-zappy-theo.berget
** File description:
** mct
*/

#include "../../include/my.h"

void mct(server_t *s)
{
    size_t size = s->arg->_width * s->arg->_height;
    size_t buffer_size = 99 * size;
    size_t max_send_size = 1024;
    char *sending = malloc(sizeof(char) * buffer_size);
    size_t sending_length = 3;

    strcpy(sending, "bct");
    if (strcmp(s->server_data->command[0], "mct") == 0) {
        for (int i = 0; i < s->arg->_width; i++) {
            for (int j = 0; j < s->arg->_height; j++) {
                sending_length += sprintf(sending + sending_length, " %d %d %d %d %d %d %d %d %d",
                i, j, s->server_data->map_content[i][j].food,
                s->server_data->map_content[i][j].linemate, s->server_data->map_content[i][j].deraumere,
                s->server_data->map_content[i][j].sibur, s->server_data->map_content[i][j].mendiane,
                s->server_data->map_content[i][j].phiras, s->server_data->map_content[i][j].thystame);
                if (sending_length >= max_send_size) {
                    send(s->server_net->current->socket, sending, max_send_size, 0);
                    print_send_to_client(s, sending);
                    memmove(sending, sending + max_send_size, sending_length - max_send_size);
                    sending_length -= max_send_size;
                }
            }
        }
        strcat(sending, "\n");
        sending_length += 1;
        while (sending_length > max_send_size) {
            send(s->server_net->current->socket, sending, max_send_size, 0);
            print_send_to_client(s, sending);
            memmove(sending, sending + max_send_size, sending_length - max_send_size);
            sending_length -= max_send_size;
        }
        send(s->server_net->current->socket, sending, sending_length, 0);
        print_send_to_client(s, sending);

        s->server_data->isCommand = 1;
    }
    free(sending);
}
