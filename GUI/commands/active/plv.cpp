/*
** EPITECH PROJECT, 2024
** B-YEP-400-MAR-4-1-zappy-theo.berget
** File description:
** plv
*/

#include "../../include/Core.hpp"


void Core::plv()
{
    std::string send;

    if (clock_plv.getElapsedTime().asSeconds() >= 0.1f) {
        for (int i = 0; i < info_players.size(); i++) {
            send_to_server("plv #" + std::to_string(info_players[i].player_number) + "\n");
            receive_from_server();
            info_players[i].level = std::stoi(vbuffer[2]);
        }
        clock_plv.restart();
    }
}
