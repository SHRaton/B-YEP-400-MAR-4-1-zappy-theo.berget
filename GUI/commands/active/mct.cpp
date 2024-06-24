/*
** EPITECH PROJECT, 2024
** B-YEP-400-MAR-4-1-zappy-theo.berget
** File description:
** mct
*/

#include "../../include/Core.hpp"

void Core::mct()
{
    if (clock_mct.getElapsedTime().asSeconds() >= 0.1f) {
        send_to_server("mct\n");
        receive_from_server();
        std::istringstream iss(sbuffer.substr(4)); // Ignorer "bct "

        ressources_grid = std::vector<std::vector<ressources>>(height, std::vector<ressources>(width));

        int x, y;
        while (iss >> x >> y) {
            int food, coal, iron, gold, diamond, emerald, netherite;
            iss >> food >> coal >> iron >> gold >> diamond >> emerald >> netherite;
            ressources_grid[x][y] = ressources(food, coal, iron, gold, diamond, emerald, netherite);
        }

        clock_mct.restart();
    }
}
