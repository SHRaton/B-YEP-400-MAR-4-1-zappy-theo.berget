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
    char *sending = malloc(sizeof(char) * buffer_size);
    if (sending == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    char *tmp = malloc(sizeof(char) * 99);
    if (tmp == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    if (strcmp(s->server_data->command[0], "mct") == 0) {
        strcpy(sending, "bct");
        for (int i = 0; i < s->arg->_width; i++) {
            for (int j = 0; j < s->arg->_height; j++) {
                sprintf(tmp, " %d %d %d %d %d %d %d %d %d",
                i, j, s->server_data->map_content[i][j].food,
                s->server_data->map_content[i][j].linemate, s->server_data->map_content[i][j].deraumere,
                s->server_data->map_content[i][j].sibur, s->server_data->map_content[i][j].mendiane,
                s->server_data->map_content[i][j].phiras, s->server_data->map_content[i][j].thystame);
                strcat(sending, tmp);
            }
        }
        send(s->server_net->current->socket, sending, strlen(sending) + 1, 0);
        //send_and_print(s, sending, s->server_net->current->socket);
        s->server_data->isCommand = 1;
    }
    free(sending);
    free(tmp);
}
