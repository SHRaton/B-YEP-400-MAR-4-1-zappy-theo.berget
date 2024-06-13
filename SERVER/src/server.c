/*
** EPITECH PROJECT, 2024
** B-YEP-400-MAR-4-1-zappy-alexandre.vittenet
** File description:
** server
*/

#include "../include/my.h"

// fonction qui initialise et démare le serveur avec les arguments définis
// et initialise la structure principale server_t puis rentre dans la boucle infinie du server
void start_server(arg_t *arg)
{
    server_t *server = malloc(sizeof(server_t));

    apply(server, arg);
    printf("\n[Arguments loaded]     [\033[32mOK\033[0m]\n");
    init_socket(server);
    printf("[Server is started]    [\033[32mOK\033[0m]\n\n");
    print_args(arg);
    for (;;) {
        handle_client(server);
    }
    free(server);
}
