/*
** EPITECH PROJECT, 2024
** B-YEP-400-MAR-4-1-zappy-theo.berget
** File description:
** login_to_server
*/

#include "../include/main.hpp"

void Display::set_map_size(int x, int y)
{
    width = x;
    height = y;
}

void Display::handleEvents4()
{
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed ||
            (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
            window.close();
        } else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
            std::cout << "Position de la souris : x = " << mousePosition.x << ", y = " << mousePosition.y << std::endl;
        }
        if (event.type == sf::Event::KeyPressed) {
            handleKeyboard(event.key);
        }
    }
}

void Display::update4()
{
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

    if (mousePosition.x >= 526 && mousePosition.x <= 1396 && mousePosition.y >= 619 && mousePosition.y <= 694) {

    }
    // Mise à jour de l'état jour/nuit
    if (clock.getElapsedTime() >= timeInterval) {
        if (isSunset) {
            isSunset = false;
            isNight = true;
        } else if (isNight) {
            isNight = false;
            isDay = true;
        } else {
            isDay = false;
            isSunset = true;
        }
        clock.restart();
    }
    // Set des textures
    window.clear(sf::Color::Black);
    sprite_water.setTexture(texture10);
    sprite_HTAG.setTexture(textureHTAG);
    sprite_A.setTexture(textureA);
    sprite_B.setTexture(textureB);
    sprite_C.setTexture(textureC);
    sprite_D.setTexture(textureD);
    sprite_UP.setTexture(textureUP);
    sprite_DOWN.setTexture(textureDOWN);
    sprite_RIGHT.setTexture(textureRIGHT);
    sprite_LEFT.setTexture(textureLEFT);
    sprite_steve.setTexture(textureSteve);


    sprite_HTAG.setScale(8, 8);
    sprite_A.setScale(8, 8);
    sprite_B.setScale(8, 8);
    sprite_C.setScale(8, 8);
    sprite_D.setScale(8, 8);
    sprite_UP.setScale(8, 8);
    sprite_DOWN.setScale(8, 8);
    sprite_RIGHT.setScale(8, 8);
    sprite_LEFT.setScale(8, 8);
    sprite_steve.setScale(5, 5);
}

void Display::render4()
{
    int i = 0, y = 0;
    surplu_x = (window.getSize().x / 2) - ((width * 128) / 2);
    surplu_y = (window.getSize().y / 2) - ((height * 128) / 2);

    if (isDay) {
        window.draw(sprite_water);
    } else if (isSunset) {
        window.draw(sprite_sunset);
    } else {
        window.draw(sprite_night);
    }

    while (map.size() > i) {
        while (map[i].size() > y) {
            if (map[i][y] == '#') {
                sprite_HTAG.setPosition(y * 128 + surplu_x, i * 128 + surplu_y);
                window.draw(sprite_HTAG);
            }
            if (map[i][y] == 'A') {
                sprite_A.setPosition(y * 128 + surplu_x, i * 128 + surplu_y);
                window.draw(sprite_A);
            }
            if (map[i][y] == 'B') {
                sprite_B.setPosition(y * 128 + surplu_x, i * 128 + surplu_y);
                window.draw(sprite_B);
            }
            if (map[i][y] == 'C') {
                sprite_C.setPosition(y * 128 + surplu_x, i * 128 + surplu_y);
                window.draw(sprite_C);
            }
            if (map[i][y] == 'D') {
                sprite_D.setPosition(y * 128 + surplu_x, i * 128 + surplu_y);
                window.draw(sprite_D);
            }
            if (map[i][y] == '-') {
                sprite_UP.setPosition(y * 128 + surplu_x, i * 128 + surplu_y);
                window.draw(sprite_UP);
            }
            if (map[i][y] == '_') {
                sprite_DOWN.setPosition(y * 128 + surplu_x, i * 128 + surplu_y);
                window.draw(sprite_DOWN);
            }
            if (map[i][y] == '<') {
                sprite_LEFT.setPosition(y * 128 + surplu_x, i * 128 + surplu_y);
                window.draw(sprite_LEFT);
            }
            if (map[i][y] == '>') {
                sprite_RIGHT.setPosition(y * 128 + surplu_x, i * 128 + surplu_y);
                window.draw(sprite_RIGHT);
            }
            y++;
        }
        y = 0;
        i++;
    }
    for (int i = 0; info_players.size() > i; i++) {
        sprite_steve.setPosition(info_players[i].pos_x, info_players[i].pos_y);
        window.draw(sprite_steve);
    }
    window.display();
}
