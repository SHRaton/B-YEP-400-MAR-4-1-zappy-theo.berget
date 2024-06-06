/*
** EPITECH PROJECT, 2024
** B-YEP-400-MAR-4-1-zappy-theo.berget
** File description:
** main
*/

#include "my.h"

void print_usage(void)
{
    dprintf(1, "USAGE: ./zappy_server -p {PORT} -x {WIDTH} -y {HEIGHT}");
    dprintf(1, " -n {NAME1 NAME2 ...} -c {NB_CLIENTS} -f {FREQUENCE}\n");
}

void print_args(arg_t *arg)
{
    dprintf(1, "port= %d / x= %d / y= %d / c= %d / _f= %d / names= ",
    arg->_port, arg->_width, arg->_height, arg->_nb_clients, arg->_frequence);
    for (int i = 0; arg->_names[i] != NULL; i++)
        dprintf(1, "%s ", arg->_names[i]);
    dprintf(1, "\n");
}

int main(int ac, char **av)
{
    arg_t *arg;

    if (parsing_argument(ac, av, arg) == 84) {
        print_usage();
        return (84);
    }
    start_server(arg);
}
