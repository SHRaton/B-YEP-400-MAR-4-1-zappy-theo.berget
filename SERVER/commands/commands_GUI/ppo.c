/*
** EPITECH PROJECT, 2024
** B-YEP-400-MAR-4-1-zappy-theo.berget
** File description:
** ppo
*/

#include "../../include/my.h"

void get_string_ppo(server_t *s, char *ret, char *str)
{
    client_t *tmp = s->server_net->current;

    s->server_net->current = s->server_net->cli_head;
    while (s->server_net->current != NULL) {
        if (s->server_net->current->isAI == 1 &&
            s->server_net->current->player_number == atoi(str)) {
            strcat(ret, " ");
            strcat(ret, int_to_str(s->server_net->current->pos_x));
            strcat(ret, " ");
            strcat(ret, int_to_str(s->server_net->current->pos_y));
            strcat(ret, " ");
            strcat(ret, int_to_str(s->server_net->current->orientation));
            strcat(ret, "\n");
        }
        s->server_net->current = s->server_net->current->next;
    }
    s->server_net->current = tmp;
}

void ppo(server_t *s)
{
    char *ret = malloc(sizeof(char) * 9888);
    if (ret == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    char *str = malloc(sizeof(char) * 9888);
    if (str == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    if (strcmp(s->server_data->command[0], "ppo") == 0) {
        strcpy(str, s->server_data->command[1]);
        str = remove_cara(str, '#');
        strcpy(ret, "ppo #");
        strcat(ret, str);
        get_string_ppo(s, ret, str);
        send(s->server_net->current->socket, ret, strlen(ret), 0);
        print_send_to_client(s, remove_cara(ret, '\n'));
        s->server_data->isCommand = 1;
    }
}
