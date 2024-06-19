/*
** EPITECH PROJECT, 2024
** B-YEP-400-MAR-4-1-zappy-theo.berget
** File description:
** commands
*/

#include "../include/main.hpp"

std::vector<std::string> Display::str_to_word_array(std::string s)
{
    std::istringstream iss(s);
    std::vector<std::string> tokens;
    std::string token;

    while (std::getline(iss, token, ' ')) {
      tokens.push_back(token);
    }
    return tokens;
}

void Display::pnw()
{
    if (vbuffer[0] == "pnw") {
        Info_Player info;
        info.player_number = std::stoi(vbuffer[1].substr(1));
        info.pos_x = std::stoi(vbuffer[2]);
        info.pos_y = std::stoi(vbuffer[3]);
        info.orientation = std::stoi(vbuffer[4]);
        info.level = std::stoi(vbuffer[5]);
        info.team_name = vbuffer[6];
        info_players.push_back(info);
        sleep(0.1);
        for (int i = 0; info_players.size() > i; i++) {
            std::cout << info_players[i].player_number << "\n";
        }
    }
}

void Display::pdi()
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
    }
}

void Display::ppo()
{
    if (clock_pos.getElapsedTime().asSeconds() >= 1.0f) {
        std::string send;
        for (int i = 0; info_players.size() > i; i++) {
            send = "ppo #" + std::to_string(info_players[i].player_number) + "\n";
            send_to_server(send);
            receive_from_server();
            info_players[i].pos_x = surplu_x + ((std::stoi(vbuffer[2]) + 1) * 128) - 140;
            info_players[i].pos_y = surplu_y + ((std::stoi(vbuffer[3]) + 1) * 128) - 180;
            info_players[i].orientation = std::stoi(vbuffer[4]);
        }
        clock_pos.restart();
    }
}

void Display::mct() {
    if (clock_mct.getElapsedTime().asSeconds() >= 1.0f) {
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

void Display::commands()
{
    pnw();
    pdi();
    ppo();
    mct();
    strcpy(buffer, "");
    sbuffer = std::string(buffer);
    vbuffer[0] = "";
}
