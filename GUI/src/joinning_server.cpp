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
    mapSizeText.setFont(font);
    mapSizeText.setCharacterSize(35); // Taille du texte
    mapSizeText.setFillColor(sf::Color::White); // Couleur du texte
    mapSizeText.setPosition(20, 965);
    mapSizeText.setString("Map Size: " + std::to_string(width) + " x " + std::to_string(height));

    greyRectangle.setSize(sf::Vector2f(310, 70)); // Taille du rectangle
    greyRectangle.setFillColor(sf::Color(128, 128, 128)); // Couleur grise
    greyRectangle.setPosition(10, 950); // Position du rectangle
}

void Display::handleEvents4()
{
    sf::Event event;
    greyRectangle2.setSize(sf::Vector2f(450, 500)); // Taille du rectangle
    greyRectangle2.setFillColor(sf::Color(128, 128, 128)); // Couleur grise
    greyRectangle2.setPosition(10, 280); // Position du rectangle
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed ||
            (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
            window.close();
        } else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
            std::cout << "Position de la souris : x = " << mousePosition.x << ", y = " << mousePosition.y << std::endl;
            handleClick(mousePosition.x, mousePosition.y);
            soundButton.play();
        } else if (event.type == sf::Event::KeyPressed && event.key.code == 55) {
            ratio *= 1.20;
            sound_zoom.play();
        } else if (event.type == sf::Event::KeyPressed && event.key.code == 56) {
            ratio /= 1.20;
            sound_dezoom.play();
        } else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R && pressed == 0) {
            countTotalResources();
            pressed = 1;
        } else if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::R) {
            pressed = 0;
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
            sound_zombie.play();
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
    for (int i = 0; info_players.size() > i; i++) {
        surplu_x = (window.getSize().x / 2) - ((width * (128 * ratio)) / 2);
        surplu_y = (window.getSize().y / 2) - ((height * (128 * ratio)) / 2);
        info_players[i].pos_x = surplu_x + (info_players_brut[i].pos_x + 1) * (128 * ratio) - (140 * ratio);
        info_players[i].pos_y = surplu_y + (info_players_brut[i].pos_y + 1) * (128 * ratio) - (180 * ratio);
        sprite_steve.setScale(5 * ratio, 5 * ratio);
    }
    if (indx != 404) {
        show_inv = info_players[indx].inventory;
    }
}

void Display::countTotalResources()
{
    int totalFood = 0, totalCoal = 0, totalIron = 0, totalGold = 0, totalDiamond = 0, totalEmerald = 0, totalNetherite = 0;

    for (const auto& row : ressources_grid) {
        for (const auto& cell : row) {
            totalFood += cell.food;
            totalCoal += cell.coal;
            totalIron += cell.iron;
            totalGold += cell.gold;
            totalDiamond += cell.diamond;
            totalEmerald += cell.emerald;
            totalNetherite += cell.netherite;
        }
    }

    totalResourcesText.setFont(font);
    totalResourcesText.setCharacterSize(36);
    totalResourcesText.setFillColor(sf::Color::White);
    totalResourcesText.setPosition(20, 300); // Position du texte

    std::string resourcesString = "Total Resources:\n\n";
    resourcesString += "Food: " + std::to_string(totalFood) + "\n";
    resourcesString += "Coal: " + std::to_string(totalCoal) + "\n";
    resourcesString += "Iron: " + std::to_string(totalIron) + "\n";
    resourcesString += "Gold: " + std::to_string(totalGold) + "\n";
    resourcesString += "Diamond: " + std::to_string(totalDiamond) + "\n";
    resourcesString += "Emerald: " + std::to_string(totalEmerald) + "\n";
    resourcesString += "Netherite: " + std::to_string(totalNetherite) + "\n";

    totalResourcesText.setString(resourcesString);
}


void Display::showPlayerResources()
{
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::White);

    // Nombre de Food
    text.setPosition(642, 990);
    text.setString(std::to_string(show_inv.food));
    window.draw(text);

    // Nombre de Coal
    text.setPosition(750, 990);
    text.setString(std::to_string(show_inv.coal));
    window.draw(text);

    // Nombre de Iron
    text.setPosition(858, 990);
    text.setString(std::to_string(show_inv.iron));
    window.draw(text);

    // Nombre de Gold
    text.setPosition(966, 990);
    text.setString(std::to_string(show_inv.gold));
    window.draw(text);

    // Nombre de Diamond
    text.setPosition(1074, 990);
    text.setString(std::to_string(show_inv.diamond));
    window.draw(text);

    // Nombre de Emerald
    text.setPosition(1182, 990);
    text.setString(std::to_string(show_inv.emerald));
    window.draw(text);

    // Nombre de Netherite
    text.setPosition(1290, 990);
    text.setString(std::to_string(show_inv.netherite));
    window.draw(text);
}


void Display::handleClick(int mouseX, int mouseY)
{
     sf::Vector2i mousePos(mouseX, mouseY);

    for (int i = 0; i < info_players.size(); i++) {
        if (info_players[i].pos_x < mousePos.x && info_players[i].pos_x + (160 * ratio) > mousePos.x && info_players[i].pos_y < mousePos.y && info_players[i].pos_y + (160 * ratio) > mousePos.y) {
            indx = i;
            std::cout << "LA ---> : (" << info_players[indx].inventory.food << " " << info_players[indx].inventory.coal << " " << info_players[indx].inventory.iron << " " << info_players[indx].inventory.gold << " " << info_players[indx].inventory.diamond << " " << info_players[indx].inventory.emerald << " " << info_players[indx].inventory.netherite << ")\n";
            break;
        }
    }

    int cellX = (mouseX - surplu_x) / (128 * ratio);
    int cellY = (mouseY - surplu_y) / (128 * ratio);

    if (cellX >= 0 && cellX < width && cellY >= 0 && cellY < height) {
        selectedResources = ressources_grid[cellY][cellX];

        std::cout << "Food: " << selectedResources.food << std::endl;
        std::cout << "Coal: " << selectedResources.coal << std::endl;
        std::cout << "Iron: " << selectedResources.iron << std::endl;
        std::cout << "Gold: " << selectedResources.gold << std::endl;
        std::cout << "Diamond: " << selectedResources.diamond << std::endl;
        std::cout << "Emerald: " << selectedResources.emerald << std::endl;
        std::cout << "Netherite: " << selectedResources.netherite << std::endl;
    }
}

void Display::render4()
{
    int i = 0, y = 0;

    // Ressources
    texture_food.loadFromFile("GUI/assets/food.png");
    texture_coal.loadFromFile("GUI/assets/coal.png");
    texture_iron.loadFromFile("GUI/assets/iron.png");
    texture_gold.loadFromFile("GUI/assets/gold.png");
    texture_diamond.loadFromFile("GUI/assets/diamond.png");
    texture_emerald.loadFromFile("GUI/assets/emerald.png");
    texture_netherite.loadFromFile("GUI/assets/netherite.png");

    // Inventaire joueur
    texture_player_inventory.loadFromFile("GUI/assets/inventory2.png");

    // Inventaire case
    texture_case_inventory.loadFromFile("GUI/assets/inventory.png");

    surplu_x = (window.getSize().x / 2) - ((width * (128 * ratio)) / 2);
    surplu_y = (window.getSize().y / 2) - ((height * (128 * ratio)) / 2);

    if (isDay) {
        window.draw(sprite_water);
    } else if (isSunset) {
        window.draw(sprite_sunset);
    } else {
        window.draw(sprite_night);
    }

    // Affichage des éléments de la carte
    while (map.size() > i) {
        while (map[i].size() > y) {
            sf::Sprite* sprite = nullptr;

            // Assignation du sprite en fonction du caractère de la carte
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
                sprite->setScale(8 * ratio, 8 * ratio);
                sprite->setPosition(y * (128 * ratio) + surplu_x, i * (128 * ratio) + surplu_y);
                window.draw(*sprite);
            }

            // Affichage des ressources sur la case actuelle
            const auto& res = ressources_grid[i][y];
                for (int j = 0; j < res.food; ++j) {
                    sprite_food.setTexture(texture_food);
                    sprite_food.setPosition(y * (128 * ratio) + surplu_x + (j * 10 * ratio), i * (128 * ratio) + surplu_y);
                    sprite_food.setScale(0.2 * ratio, 0.2 * ratio);
                    window.draw(sprite_food);
                }
                for (int j = 0; j < res.coal; ++j) {
                    sprite_coal.setTexture(texture_coal);
                    sprite_coal.setPosition(y * (128 * ratio) + surplu_x + (50 * ratio) + (j * 10 * ratio), i * (128 * ratio) + surplu_y + (50 * ratio));
                    sprite_coal.setScale(0.2 * ratio, 0.2 * ratio);
                    window.draw(sprite_coal);
                }
                for (int j = 0; j < res.iron; ++j) {
                    sprite_iron.setTexture(texture_iron);
                    sprite_iron.setPosition(y * (128 * ratio) + surplu_x + (33 * ratio) + (j * 10 * ratio), i * (128 * ratio) + surplu_y + (33 * ratio));
                    sprite_iron.setScale(0.1 * ratio, 0.1 * ratio);
                    window.draw(sprite_iron);
                }
                for (int j = 0; j < res.gold; ++j) {
                    sprite_gold.setTexture(texture_gold);
                    sprite_gold.setPosition(y * (128 * ratio) + surplu_x + (67 * ratio) + (j * 10 * ratio), i * (128 * ratio) + surplu_y + (67 * ratio));
                    sprite_gold.setScale(0.1 * ratio, 0.1 * ratio);
                    window.draw(sprite_gold);
                }
                for (int j = 0; j < res.diamond; ++j) {
                    sprite_diamond.setTexture(texture_diamond);
                    sprite_diamond.setPosition(y * (128 * ratio) + surplu_x + (48 * ratio) + (j * 10 * ratio), i * (128 * ratio) + surplu_y + (89 * ratio));
                    sprite_diamond.setScale(0.2 * ratio, 0.2 * ratio);
                    window.draw(sprite_diamond);
                }
                for (int j = 0; j < res.emerald; ++j) {
                    sprite_emerald.setTexture(texture_emerald);
                    sprite_emerald.setPosition(y * (128 * ratio) + surplu_x + (16 * ratio) + (j * 10 * ratio), i * (128 * ratio) + surplu_y + (57 * ratio));
                    sprite_emerald.setScale(0.2 * ratio, 0.2 * ratio);
                    window.draw(sprite_emerald);
                }
                for (int j = 0; j < res.netherite; ++j) {
                    sprite_netherite.setTexture(texture_netherite);
                    sprite_netherite.setPosition(y * (128 * ratio) + surplu_x + (55 * ratio) + (j * 10 * ratio), i * (128 * ratio) + surplu_y + (12 * ratio));
                    sprite_netherite.setScale(0.2 * ratio, 0.2 * ratio);
                    window.draw(sprite_netherite);
                }
            y++;
        }
        y = 0;
        i++;
    }

    // Déplacement du joueur
    for (int i = 0; info_players.size() > i; i++) {
        text_level.setFont(font);
        text_level.setCharacterSize(25 * ratio);
        text_level.setFillColor(sf::Color::White);
        text_level.setPosition(info_players[i].pos_x, info_players[i].pos_y - (10 * ratio));
        text_level.setString(std::to_string(info_players[i].level));
        text_team_name.setFont(font);
        text_team_name.setCharacterSize(25 * ratio);
        text_team_name.setFillColor(sf::Color::White);
        text_team_name.setPosition(info_players[i].pos_x + (50 * ratio), info_players[i].pos_y - (10 * ratio));
        text_team_name.setString(info_players[i].team_name);
        sprite_steve.setPosition(info_players[i].pos_x, info_players[i].pos_y);
        sprite_steve.setScale(5 * ratio, 5 * ratio);
        if (info_players[i].animation == 1 && info_players[i].orientation == 1) {
            textureSteve.loadFromFile("GUI/assets/walk_up.png");
            sprite_steve.setTexture(textureSteve);
        }
        if (info_players[i].animation == 1 && info_players[i].orientation == 3) {
            textureSteve.loadFromFile("GUI/assets/walk_down.png");
            sprite_steve.setTexture(textureSteve);
        }
        if (info_players[i].animation == 1 && info_players[i].orientation == 4) {
            textureSteve.loadFromFile("GUI/assets/left_walk.png");
            sprite_steve.setTexture(textureSteve);
        }
        if (info_players[i].animation == 1 && info_players[i].orientation == 2) {
            textureSteve.loadFromFile("GUI/assets/right_walk.png");
            sprite_steve.setTexture(textureSteve);
        }
        if (info_players[i].animation == 0) {
            textureSteve.loadFromFile("GUI/assets/idle.png");
            sprite_steve.setTexture(textureSteve);
        }
        window.draw(sprite_steve);
        window.draw(text_level);
        window.draw(text_team_name);
    }

    // Affichage de l'inventaire joueur
    sprite_player_inventory.setPosition(560, 935);
    sprite_player_inventory.setScale(1.5, 1.5);
    sprite_player_inventory.setTexture(texture_player_inventory);
    window.draw(sprite_player_inventory);

    showPlayerResources();

    // Affichage de l'inventaire case
    sprite_case_inventory.setPosition(1490, 275);
    sprite_case_inventory.setTexture(texture_case_inventory);
    window.draw(sprite_case_inventory);

    // Affichage des informations des ressources sélectionnées
    resourceText.setFont(font);
    resourceText.setCharacterSize(36);
    resourceText.setFillColor(sf::Color::White);

    //Nombre de Food sur la case
    resourceText.setPosition(1770, 305);
    resourceText.setString(std::to_string(selectedResources.food));
    window.draw(resourceText);

    //Nombre de Coal sur la case
    resourceText.setPosition(1770, 387);
    resourceText.setString(std::to_string(selectedResources.coal));
    window.draw(resourceText);

    //Nombre de Iron sur la case
    resourceText.setPosition(1770, 460);
    resourceText.setString(std::to_string(selectedResources.iron));
    window.draw(resourceText);

     //Nombre de Gold sur la case
    resourceText.setPosition(1770, 531);
    resourceText.setString(std::to_string(selectedResources.gold));
    window.draw(resourceText);

     //Nombre de Diamond sur la case
    resourceText.setPosition(1770, 600);
    resourceText.setString(std::to_string(selectedResources.diamond));
    window.draw(resourceText);

     //Nombre de Emerald sur la case
    resourceText.setPosition(1770, 680);
    resourceText.setString(std::to_string(selectedResources.emerald));
    window.draw(resourceText);

     //Nombre Netherite sur la case
    resourceText.setPosition(1770, 768);
    resourceText.setString(std::to_string(selectedResources.netherite));
    window.draw(resourceText);

    window.draw(greyRectangle);
    window.draw(mapSizeText);
    if (pressed == 1) {
        window.draw(greyRectangle2);
        window.draw(totalResourcesText);
    }
    window.display();
}


