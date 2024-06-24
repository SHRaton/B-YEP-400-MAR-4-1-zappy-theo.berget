/*
** EPITECH PROJECT, 2024
** B-YEP-400-MAR-4-1-zappy-theo.berget
** File description:
** pdi
*/

#include "../../include/Core.hpp"

void Core::pdi()
{
    if (vbuffer[0] == "pdi") {
        int player_nb = std::stoi(vbuffer[1].substr(1));
        int index = 0;
        for (int i = 0; info_players.size() > i; i++) {
            if (info_players[i].player_number == player_nb) {
                index = i;
            }
        }
        info_players.erase(info_players.begin() + index);
        info_players_brut.erase(info_players_brut.begin() + index);
    }
}
