/*
** EPITECH PROJECT, 2024
** B-YEP-400-MAR-4-1-zappy-theo.berget
** File description:
** main
*/

#include <stdio.h>

int parsing_argument(int ac, char **av)
{
    if (ac < 7) {
        dprintf(1, "USAGE: ./zappy_server -p {PORT} -x {WIDTH} -y {HEIGHT} -n {NAME1 NAME2 ...} -c {NB_CLIENTS} -f {FREQUENCE}\n");
        return 84;
    }
}

int main(int ac, char **av)
{
    if (parsing_argument(ac, av) == 84) {
        return (84);
    }
    
}
