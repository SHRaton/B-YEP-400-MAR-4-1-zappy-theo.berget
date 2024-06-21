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
        info_players_brut.push_back(info);
        sleep(0.1);
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
        info_players_brut.erase(info_players_brut.begin() + index);
    }
}

void Display::ppo()
{
    if (clock_pos.getElapsedTime().asSeconds() >= 1.0f) {
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


void Display::mct()
{
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

void Display::pin()
{
    if (clock_pin.getElapsedTime().asSeconds() >= 1.0f) {
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

void Display::commands()
{
    pnw();
    pdi();
    ppo();
    mct();
    //pin();
    strcpy(buffer, "");
    sbuffer = std::string(buffer);
    vbuffer[0] = "";
}
