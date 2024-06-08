/*
** EPITECH PROJECT, 2024
** B-YEP-400-MAR-4-1-zappy-alexandre.vittenet
** File description:
** init
*/

#include "../include/my.h"

// Affiche le manuel d'utilisation du programme
void print_usage(void)
{
    dprintf(1, "USAGE: ./zappy_server -p {PORT} -x {WIDTH} -y {HEIGHT}");
    dprintf(1, " -n {NAME1 NAME2 ...} -c {NB_CLIENTS} -f {FREQUENCE}\n");
}

// Affiche tout les noms de teams définis dans le flag -n
void print_names(arg_t *arg)
{
    for (int i = 0; arg->_names[i] != NULL; i++) {
        dprintf(1, "\033[36m%s\033[0m", arg->_names[i]);
        if (arg->_names[i + 1] != NULL) {
            dprintf(1, ", ");
        }
    }
    dprintf(1, "\n");
}

// Affiche des informations sur le serveur a son lancement
void print_args(arg_t *arg)
{
    dprintf(1, ".___________\033[37mZAPPY_SERVER\033[0m___________.\n");
    dprintf(1, "|\n");
    dprintf(1, "|\033[34m__SERVER_HOST_ON\033[0m    [\033[36m127.0.0.1\
    \033[0m]\n");
    dprintf(1, "|\n");
    dprintf(1, "|\033[34m__PORT\033[0m              \033[36m%d\033[0m\n",
    arg->_port);
    dprintf(1, "|\n");
    dprintf(1, "|\033[34m__MAP_SIZE\033[0m          {\033[36m%d\033[0m x\
    \033[36m%d\033[0m}\n", arg->_width, arg->_height);
    dprintf(1, "|\n");
    dprintf(1, "|\033[34m__TEAMS\033[0m             "); print_names(arg);
    dprintf(1, "|\n");
    dprintf(1, "|\033[34m__NB_CLIENTS\033[0m        \033[36m%d\033[0m\n",
    arg->_nb_clients);
    dprintf(1, "|\n");
    dprintf(1, "|\033[34m__FREQUENCE\033[0m         \033[36m%d\033[0m\n",
    arg->_frequence);
    dprintf(1, "|__________________________________.\n\n");
}
