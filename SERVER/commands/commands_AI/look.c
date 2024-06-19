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
    int x = 0, y = 0;
    int line_sz = 1;
    int tmp = 0, cmpt = 1;
    int ori_x = 0, ori_y = 0;
    if (strcmp(s->server_data->command[0], "Look") == 0) {
        if (s->server_net->current->orientation == 1) {
            ori_x = 1;
            ori_y = -1;
        }
        if (s->server_net->current->orientation == 2) {
            ori_x = 1;
            ori_y = 1;
        }
        if (s->server_net->current->orientation == 3) {
            ori_x = -1;
            ori_y = 1;
        }
        if (s->server_net->current->orientation == 4) {
            ori_x = -1;
            ori_y = -1;
        }
        x = s->server_net->current->pos_x;
        y = s->server_net->current->pos_y;
        strcpy(sending, "[player");
        for (int i = 0; i < 4; i++) {
            //dprintf(1, "(%d %d)\n", x, y);
            if (y < 0 || y > s->arg->_height || x < 0 || x > s->arg->_width) {
                // do nothing
            } else {
                if (s->server_data->map_content[y][x].food > 0) {
                    strcat(sending, " food");
                }
                if (s->server_data->map_content[y][x].linemate > 0) {
                    strcat(sending, " linemate");
                }
                if (s->server_data->map_content[y][x].deraumere > 0) {
                    strcat(sending, " deraumere");
                }
                if (s->server_data->map_content[y][x].sibur > 0) {
                    strcat(sending, " sibur");
                }
                if (s->server_data->map_content[y][x].mendiane > 0) {
                    strcat(sending, " mendiane");
                }
                if (s->server_data->map_content[y][x].phiras > 0) {
                    strcat(sending, " phiras");
                }
                if (s->server_data->map_content[y][x].thystame > 0) {
                    strcat(sending, " thystame");
                }
            }
            strcat(sending, ",");
            if (cmpt < line_sz) {
                cmpt++;
                x += ori_x;
                //dprintf(1, "X\n");
            } else {
                y += ori_y;
                cmpt = 1;
                x -= line_sz * ori_x;
                line_sz += 2;
                //dprintf(1, "Y\n");
            }

        }
        sending[strlen(sending) - 1] = '\0';
        strcat(sending, "]");
        send_and_print(s, sending, s->server_net->current->socket);
        s->server_data->isCommand = 1;
    }
}
