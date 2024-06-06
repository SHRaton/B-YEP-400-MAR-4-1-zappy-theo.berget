/*
** EPITECH PROJECT, 2024
** B-YEP-400-MAR-4-1-zappy-theo.berget
** File description:
** server
*/

#include "my.h"

void start_server(arg_t *arg)
{
    printf("start server\n");
    print_args(arg);

    server_t *server = malloc(sizeof(server_t));
    apply(server, arg);
    init_socket(server);
    exit (0);
    for (;;) {
        dprintf(1, "%d\n", server->arg->_port);
    }
    free(server);
}
