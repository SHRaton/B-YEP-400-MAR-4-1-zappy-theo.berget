/*
** EPITECH PROJECT, 2024
** B-YEP-400-MAR-4-1-zappy-theo.berget
** File description:
** map
*/

#include "../include/Core.hpp"

void space(int n_, std::vector<std::string> &map)
{
    while (n_ > 0) {
        map[map.size() - 1].push_back('#');
        n_--;
    }
}

void barx(int lengthx, int lengthy, char g, char m, char d, std::vector<std::string> &map)
{
    int force = 1;
    int barl = lengthx - 2;
    if (lengthy == 1 || lengthx == 1) {
        force = 0;
    }
    if (lengthx > 1) {
        map[map.size() - 1].push_back(g);
    }
    while (barl > 0) {
        barl--;
        map[map.size() - 1].push_back(m);
    }
    map[map.size() - 1].push_back(d);
    map.push_back("");
}

void bary(int lengthx, int lengthy, std::vector<std::string> &map)
{
    int barl = lengthy - 2;
    while (barl > 0) {
        barl--;
        map[map.size() - 1].push_back('<');
        space(lengthx - 2, map);
        if (lengthx > 1) {
            map[map.size() - 1].push_back('>');
        }
        map.push_back("");
    }
}

void error()
{
    std::cout << "invalid size." << std::endl;
    exit (84);
}

std::vector<std::string> Core::generate_map(int x, int y)
{
    std::vector<std::string> map;
    if (x < 1 || y < 1) {
        error();
    } else {
        map.push_back("");
        barx(x, y, 'A', '-', 'B', map);
        bary(x, y, map);
        if (y != 1) {
            barx(x, y, 'C', '_', 'D', map);
        }
    }
    map.pop_back();
    return (map);
}
