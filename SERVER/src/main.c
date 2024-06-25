/*
** EPITECH PROJECT, 2024
** B-YEP-400-MAR-4-1-zappy-alexandre.vittenet
** File description:
** main
*/

#include "../include/my.h"

// Fonction principale
int main(int ac, char **av)
{
    arg_t *arg = malloc(sizeof(arg_t));

    if (parsing_argument(ac, av, arg) == 84) {
        print_usage();
        return (84);
    }
    start_server(arg);
}
