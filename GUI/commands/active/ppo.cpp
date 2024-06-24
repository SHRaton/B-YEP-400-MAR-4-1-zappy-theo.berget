/*
** EPITECH PROJECT, 2024
** B-YEP-400-MAR-4-1-zappy-theo.berget
** File description:
** ppo
*/

#include "../../include/Core.hpp"

void Core::ppo()
{
    if (clock_pos.getElapsedTime().asSeconds() >= 0.1f) {
        std::string send;
        for (int i = 0; i < info_players.size(); i++) {
            send = "ppo #" + std::to_string(info_players[i].player_number) + "\n";
            send_to_server(send);
            receive_from_server();
            info_players_brut[i].pos_x = std::stoi(vbuffer[2]);
            info_players_brut[i].pos_y = std::stoi(vbuffer[3]);
            info_players_brut[i].orientation = std::stoi(vbuffer[4]);

            surplu_x = (window.getSize().x / 2) - ((width * (128 * ratio)) / 2);
            surplu_y = (window.getSize().y / 2) - ((height * (128 * ratio)) / 2);

            int new_pos_y = surplu_y + ((std::stoi(vbuffer[3]) + 1) * (128 * ratio)) - (180 * ratio);
            int new_pos_x = surplu_x + ((std::stoi(vbuffer[2]) + 1) * (128 * ratio)) - (140 * ratio);

            // Vérifier si Steve se déplace vers le haut
            if (new_pos_y < info_players[i].pos_y) {
                info_players[i].animation = 1;
            } else if (new_pos_y > info_players[i].pos_y) {
                info_players[i].animation = 1;
            } else if (new_pos_x < info_players[i].pos_x) {
                info_players[i].animation = 1;
            } else if (new_pos_x > info_players[i].pos_x) {
                info_players[i].animation = 1;
            } else {
                info_players[i].animation = 0;
            }
            info_players[i].pos_x = new_pos_x;
            info_players[i].pos_y = new_pos_y;
            info_players[i].orientation = std::stoi(vbuffer[4]);
        }
        clock_pos.restart();
    }
}
