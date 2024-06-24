/*
** EPITECH PROJECT, 2024
** B-YEP-400-MAR-4-1-zappy-theo.berget
** File description:
** pin
*/

#include "../../include/Core.hpp"

void Core::pin()
{
    if (clock_pin.getElapsedTime().asSeconds() >= 0.1f) {
        for (int i = 0; i < info_players.size(); i++) {
            send_to_server("pin #" + std::to_string(info_players[i].player_number) + "\n");
            receive_from_server();
            int pnb, x, y, index;
            pnb = std::stoi(vbuffer[1].substr(1));
            x = std::stoi(vbuffer[2]);
            y = std::stoi(vbuffer[3]);
            info_players[i].inventory.food = std::stoi(vbuffer[4]);
            info_players[i].inventory.coal = std::stoi(vbuffer[5]);
            info_players[i].inventory.iron = std::stoi(vbuffer[6]);
            info_players[i].inventory.gold = std::stoi(vbuffer[7]);
            info_players[i].inventory.diamond = std::stoi(vbuffer[8]);
            info_players[i].inventory.emerald = std::stoi(vbuffer[9]);
            info_players[i].inventory.netherite = std::stoi(vbuffer[10]);
            std::cout << pnb << x << y << info_players[i].inventory.food << info_players[i].inventory.coal << info_players[i].inventory.iron << info_players[i].inventory.gold << info_players[i].inventory.diamond << info_players[i].inventory.emerald << info_players[i].inventory.netherite;
        }
        clock_pin.restart();
    }
}