/*
** EPITECH PROJECT, 2024
** B-YEP-400-MAR-4-1-zappy-alexandre.vittenet
** File description:
** init
*/

#include "../include/my.h"

void init_map_content(server_t *s)
{
    double densities[] = {0.5, 0.3, 0.15, 0.1, 0.1, 0.08, 0.05};
    int total_resources = (s->arg->_width - 2) * (s->arg->_height - 2);
    int resources_count[] = {0, 0, 0, 0, 0, 0, 0};

    for (int k = 0; k < 7; k++) {
        int expected_count = total_resources * densities[k];
        while (resources_count[k] < expected_count) {
            int i = rand() % (s->arg->_height - 2) + 1;
            int j = rand() % (s->arg->_width - 2) + 1;
            switch (k) {
                case 0:
                    s->server_data->map_content[i][j].food++;
                    break;
                case 1:
                    s->server_data->map_content[i][j].linemate++;
                    break;
                case 2:
                    s->server_data->map_content[i][j].deraumere++;
                    break;
                case 3:
                    s->server_data->map_content[i][j].sibur++;
                    break;
                case 4:
                    s->server_data->map_content[i][j].mendiane++;
                    break;
                case 5:
                    s->server_data->map_content[i][j].phiras++;
                    break;
                case 6:
                    s->server_data->map_content[i][j].thystame++;
                    break;
            }
            resources_count[k]++;
        }
    }
    for (int i = 0; i < s->arg->_width; i++) {
        for (int j = 0; j < s->arg->_height; j++) {
            dprintf(1, "[%d][%d] (%d %d %d %d %d %d %d)\n", i, j,
            s->server_data->map_content[i][j].food, s->server_data->map_content[i][j].linemate,
            s->server_data->map_content[i][j].deraumere, s->server_data->map_content[i][j].sibur,
            s->server_data->map_content[i][j].mendiane, s->server_data->map_content[i][j].phiras,
            s->server_data->map_content[i][j].thystame);
        }
    }
}


// Fonction qui initialise toutes les variables de la structure server_t
// et transpose la structure arg_t dans une instance de server_t
// pour tout centraliser dans server_t et n'utiliser plus que
// cette unique structure dans tout le programme
void apply(server_t *s, arg_t *arg)
{
    s->arg = malloc(sizeof(arg_t));
    if (s->arg == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    s->arg = arg;
    s->server_net = malloc(sizeof(server_net_t));
    if (s->server_net == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    s->server_data = malloc(sizeof(server_data_t));
    if (s->server_data == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    s->server_net->server_socket = 0;
    s->server_net->client_addr_len = sizeof(s->server_net->client_addr);
    s->server_net->cli_head = NULL;
    s->server_net->current = s->server_net->cli_head;
    s->server_net->max_socket = 0;
    s->server_net->result = 0;
    s->server_net->new_socket = 0;
    s->server_data->isCommand = 0;
    s->server_data->teams = malloc(sizeof(char *) * 9888);
    if (s->server_data->teams == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; s->arg->_names[i] != NULL; i++) {
        s->server_data->teams[i] = malloc(sizeof(char) * 9888);
        if (s->server_data->teams[i] == NULL) {
            perror("malloc");
            exit(EXIT_FAILURE);
        }
        strcpy(s->server_data->teams[i], s->arg->_names[i]);
        strcat(s->server_data->teams[i], ":");
        strcat(s->server_data->teams[i], int_to_str(arg->_nb_clients));
    }
    s->server_data->player_nb = 1;
    s->server_data->map_content = malloc(s->arg->_width * sizeof(case_t *));
    if (s->server_data->map_content == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < s->arg->_width; i++) {
        s->server_data->map_content[i] = malloc(s->arg->_height * sizeof(case_t));
        if (s->server_data->map_content[i] == NULL) {
            perror("malloc");
            exit(EXIT_FAILURE);
        }
    }
    s->server_data->launch_time = time(NULL);
    init_map_content(s);
}

// Fonction utilitaire qui permet de pouvoir réutiliser un port récemment
// fermé afin de faciliter les tests et le debug du programme
void re_use_port(server_t *s)
{
    int reuseaddr;

    reuseaddr = 1;
    if (setsockopt(s->server_net->server_socket, SOL_SOCKET,
    SO_REUSEADDR, &reuseaddr, sizeof(int)) == -1) {
        perror("setsockopt failed");
        close(s->server_net->server_socket);
        exit(EXIT_FAILURE);
    }
}

// Fonction qui initialise le socket du serveur a partir du localhost
// et héberge le serveur sur le port donné en argument.
void init_socket(server_t *s)
{
    s->server_net->server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (s->server_net->server_socket == -1) {
        exit(EXIT_FAILURE);
    }
    s->server_net->server_addr.sin_family = AF_INET;
    s->server_net->server_addr.sin_addr.s_addr = INADDR_ANY;
    s->server_net->server_addr.sin_port = htons(s->arg->_port);
    re_use_port(s);
    if (bind(s->server_net->server_socket,
    (struct sockaddr*)&s->server_net->server_addr,
    sizeof(s->server_net->server_addr)) == -1) {
        perror("Bind failed");
        close(s->server_net->server_socket);
        exit(EXIT_FAILURE);
    }
    if (listen(s->server_net->server_socket, 5) == -1) {
        perror("Listen failed");
        close(s->server_net->server_socket);
        exit(EXIT_FAILURE);
    }
}
