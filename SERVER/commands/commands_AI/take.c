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
        if (strcmp(s->server_data->command[1], "food") == 0) {
            s->server_net->current->inventory->food += s->server_data->map_content[s->server_net->current->pos_y][s->server_net->current->pos_x].food;
            s->server_data->map_content[s->server_net->current->pos_y][s->server_net->current->pos_x].food = 0;
        }
        if (strcmp(s->server_data->command[1], "linemate") == 0) {
            s->server_net->current->inventory->linemate += s->server_data->map_content[s->server_net->current->pos_y][s->server_net->current->pos_x].linemate;
            s->server_data->map_content[s->server_net->current->pos_y][s->server_net->current->pos_x].linemate = 0;
        }
        if (strcmp(s->server_data->command[1], "deraumere") == 0) {
            s->server_net->current->inventory->deraumere += s->server_data->map_content[s->server_net->current->pos_y][s->server_net->current->pos_x].deraumere;
            s->server_data->map_content[s->server_net->current->pos_y][s->server_net->current->pos_x].deraumere = 0;
        }
        if (strcmp(s->server_data->command[1], "sibur") == 0) {
            s->server_net->current->inventory->sibur += s->server_data->map_content[s->server_net->current->pos_y][s->server_net->current->pos_x].sibur;
            s->server_data->map_content[s->server_net->current->pos_y][s->server_net->current->pos_x].sibur = 0;
        }
        if (strcmp(s->server_data->command[1], "mendiane") == 0) {
            s->server_net->current->inventory->mendiane += s->server_data->map_content[s->server_net->current->pos_y][s->server_net->current->pos_x].mendiane;
            s->server_data->map_content[s->server_net->current->pos_y][s->server_net->current->pos_x].mendiane = 0;
        }
        if (strcmp(s->server_data->command[1], "phiras") == 0) {
            s->server_net->current->inventory->phiras += s->server_data->map_content[s->server_net->current->pos_y][s->server_net->current->pos_x].phiras;
            s->server_data->map_content[s->server_net->current->pos_y][s->server_net->current->pos_x].phiras = 0;
        }
        if (strcmp(s->server_data->command[1], "thystame") == 0) {
            s->server_net->current->inventory->thystame += s->server_data->map_content[s->server_net->current->pos_y][s->server_net->current->pos_x].thystame;
            s->server_data->map_content[s->server_net->current->pos_y][s->server_net->current->pos_x].thystame = 0;
        }
        send_and_print(s, "ok\n", s->server_net->current->socket);
        s->server_data->isCommand = 1;
    }
}
