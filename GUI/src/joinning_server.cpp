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

void Display::handleEvents4() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed ||
            (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
            window.close();
        } else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
            std::cout << "Position de la souris : x = " << mousePosition.x << ", y = " << mousePosition.y << std::endl;
            handleClick(mousePosition.x, mousePosition.y);
        }
        if (event.type == sf::Event::KeyPressed) {
            handleKeyboard(event.key);
        }
    }
}

void Display::handleClick(int mouseX, int mouseY)
{
    int cellX = (mouseX - surplu_x) / 128;
    int cellY = (mouseY - surplu_y) / 128;

    if (cellX >= 0 && cellX < width && cellY >= 0 && cellY < height) {
        const auto& res = ressources_grid[cellY][cellX];
        std::cout << "Resources in cell (" << cellX << ", " << cellY << "):" << std::endl;
        std::cout << "Food: " << res.food << std::endl;
        std::cout << "Coal: " << res.coal << std::endl;
        std::cout << "Iron: " << res.iron << std::endl;
        std::cout << "Gold: " << res.gold << std::endl;
        std::cout << "Diamond: " << res.diamond << std::endl;
        std::cout << "Emerald: " << res.emerald << std::endl;
        std::cout << "Netherite: " << res.netherite << std::endl;
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

void Display::render4() {
    int i = 0, y = 0;

    //ressources
    texture_food.loadFromFile("GUI/assets/food.png");
    texture_coal.loadFromFile("GUI/assets/coal.png");
    texture_iron.loadFromFile("GUI/assets/iron.png");
    texture_gold.loadFromFile("GUI/assets/gold.png");
    texture_diamond.loadFromFile("GUI/assets/diamond.png");
    texture_emerald.loadFromFile("GUI/assets/emerald.png");
    texture_netherite.loadFromFile("GUI/assets/netherite.png");

    //Inventaire joueur
    texture_player_inventory.loadFromFile("GUI/assets/inventory2.png");

    //Inventaire case
    texture_case_inventory.loadFromFile("GUI/assets/inventory.png");

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
            sf::Sprite* sprite = nullptr;

            if (map[i][y] == '#') sprite = &sprite_HTAG;
            if (map[i][y] == 'A') sprite = &sprite_A;
            if (map[i][y] == 'B') sprite = &sprite_B;
            if (map[i][y] == 'C') sprite = &sprite_C;
            if (map[i][y] == 'D') sprite = &sprite_D;
            if (map[i][y] == '-') sprite = &sprite_UP;
            if (map[i][y] == '_') sprite = &sprite_DOWN;
            if (map[i][y] == '<') sprite = &sprite_LEFT;
            if (map[i][y] == '>') sprite = &sprite_RIGHT;

            if (sprite) {
                sprite->setPosition(y * 128 + surplu_x, i * 128 + surplu_y);
                window.draw(*sprite);
            }

            const auto& res = ressources_grid[i][y];
            if (res.food > 0) {
                // Dessiner la nourriture
                sprite_food.setTexture(texture_food);
                sprite_food.setPosition(y * 128 + surplu_x, i * 128 + surplu_y);
                sprite_food.setScale(0.2, 0.2);
                window.draw(sprite_food);
            }
            if (res.coal > 0) {
                // Dessiner le charbon
                sprite_coal.setTexture(texture_coal);
                sprite_coal.setPosition(y * 128 + surplu_x + 50, i * 128 + surplu_y + 50);
                sprite_coal.setScale(0.2, 0.2);
                window.draw(sprite_coal);
            }
            if (res.iron > 0) {
                // Dessiner le fer
                sprite_iron.setTexture(texture_iron);
                sprite_iron.setPosition(y * 128 + surplu_x + 33, i * 128 + surplu_y + 33);
                sprite_iron.setScale(0.1, 0.1);
                window.draw(sprite_iron);
            }
            if (res.gold > 0) {
                // Dessiner l'or
                sprite_gold.setTexture(texture_gold);
                sprite_gold.setPosition(y * 128 + surplu_x + 67, i * 128 + surplu_y + 67);
                sprite_gold.setScale(0.1, 0.1);
                window.draw(sprite_gold);
            }
            if (res.diamond > 0) {
                // Dessiner le diamant
                sprite_diamond.setTexture(texture_diamond);
                sprite_diamond.setPosition(y * 128 + surplu_x + 89, i * 128 + surplu_y + 89);
                sprite_diamond.setScale(0.2, 0.2);
                window.draw(sprite_diamond);
            }
            if (res.emerald > 0) {
                // Dessiner l'émeraude
                sprite_emerald.setTexture(texture_emerald);
                sprite_emerald.setPosition(y * 128 + surplu_x + 121, i * 128 + surplu_y + 121);
                sprite_emerald.setScale(0.2, 0.2);
                window.draw(sprite_emerald);
            }
            if (res.netherite > 0) {
                // Dessiner le netherite
                sprite_netherite.setTexture(texture_netherite);
                sprite_netherite.setPosition(y * 128 + surplu_x + 55, i * 128 + surplu_y + 12);
                sprite_netherite.setScale(0.2, 0.2);
                ;window.draw(sprite_netherite);
            }
            y++;
        }
        y = 0;
        i++;
    }
    
    // déplacement player
    for (int i = 0; info_players.size() > i; i++) {
        sprite_steve.setPosition(info_players[i].pos_x, info_players[i].pos_y);
        if (animation == 1) {
            textureSteve.loadFromFile("GUI/assets/walk_up.png");
            sprite_steve.setTexture(textureSteve);
        }
        window.draw(sprite_steve);
    }

    //set texture inventory player + draw
    sprite_player_inventory.setPosition(560, 935);
    sprite_player_inventory.setScale(1.5, 1.5);
    sprite_player_inventory.setTexture(texture_player_inventory);
    window.draw(sprite_player_inventory);

    //set texture case player + draw
    sprite_case_inventory.setPosition(17, 300);
    sprite_case_inventory.setTexture(texture_case_inventory);
    window.draw(sprite_case_inventory);


    window.display();
}

