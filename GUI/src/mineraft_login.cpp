/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** server_menu
*/

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "../include/main.hpp"

void Display::handleMouseClick3(const sf::Vector2i& mousePosition)
{
    select_button = 0;

    if (mousePosition.x >= 526 && mousePosition.x <= 1396 && mousePosition.y >= 619 && mousePosition.y <= 694) {
        soundButton.play();
        if (init_socket_client() == 9) {
            failed_connection = 1;
        }
    } else if (mousePosition.x >= 517 && mousePosition.x <= 1406 && mousePosition.y >= 272 && mousePosition.y <= 365) {
        soundButton.play();
        select_button = 1;
        selectionRectangle.setSize(sf::Vector2f(1406 - 517 - 4, 365 - 272 - 4));
        selectionRectangle.setPosition(517 + 2, 272 + 2);
    } else if (mousePosition.x >= 519 && mousePosition.x <= 1407 && mousePosition.y >= 448 && mousePosition.y <= 545) {
        soundButton.play();
        select_button = 2;
        selectionRectangle.setSize(sf::Vector2f(1407 - 519 - 6, 545 - 448 - 6));
        selectionRectangle.setPosition(519 + 1, 448 + 1);
    } else {
        select_button = 0;
        selectionRectangle.setSize(sf::Vector2f(0, 0));
    }
}



char keyToAscii(sf::Keyboard::Key key, bool shift)
{
    if (key >= sf::Keyboard::A && key <= sf::Keyboard::Z) {
        return shift ? 'A' + (key - sf::Keyboard::A) : 'a' + (key - sf::Keyboard::A);
    } else if (key >= sf::Keyboard::Num0 && key <= sf::Keyboard::Num9) {
        return '0' + (key - sf::Keyboard::Num0);
    } else if (key >= sf::Keyboard::Numpad0 && key <= sf::Keyboard::Numpad9) {
        return '0' + (key - sf::Keyboard::Numpad0);
    } else {
        switch (key) {
            case sf::Keyboard::Space: return ' ';
            case sf::Keyboard::Tab: return '\t';
            case sf::Keyboard::Comma: return shift ? '?' : ',';
            case sf::Keyboard::SemiColon: return shift ? '.' : ';';
            case sf::Keyboard::Slash: return shift ? '/' : ':';
            case sf::Keyboard::Period: return shift ? ':' : '.';
            case sf::Keyboard::BackSlash: return shift ? '|' : '\\';
            case sf::Keyboard::Tilde: return shift ? '~' : '`';
            case sf::Keyboard::Equal: return shift ? '+' : '=';
            case sf::Keyboard::Dash: return shift ? '_' : '-';
            case sf::Keyboard::LBracket: return shift ? '{' : '[';
            case sf::Keyboard::RBracket: return shift ? '}' : ']';
            case sf::Keyboard::Quote: return shift ? '"' : '\'';
            default: return '\0';
        }
    }
}

void Display::handleKeyboard(sf::Event::KeyEvent key)
{
    bool shift = key.shift;
    char letter = keyToAscii(key.code, shift);

    if (select_button == 1) {
        if (key.code == sf::Keyboard::Backspace) {
            if (!ip_str.empty()) {
                ip_str.pop_back();
            }
        } else if (letter != '\0') {   
            ip_str = ip_str + letter;
        }
    }
    if (select_button == 2) {
        if (key.code == sf::Keyboard::Backspace) {
            if (!port_str.empty()) {
                port_str.pop_back();
            }
        } else if (letter != '\0') {   
            port_str = port_str + letter;
        }
    }
}

void Display::handleEvents3()
{
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed || 
            (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
            window.close();
        } else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
            std::cout << "Position de la souris : x = " << mousePosition.x << ", y = " << mousePosition.y << std::endl;
            handleMouseClick3(mousePosition);
        }
        if (event.type == sf::Event::KeyPressed) {
            handleKeyboard(event.key);
        }
    }
}

void Display::update3()
{
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

        if (mousePosition.x >= 526 && mousePosition.x <= 1396 && mousePosition.y >= 619 && mousePosition.y <= 694) {
            sprite_login.setTexture(texture7);
        } else if (mousePosition.x >= 517 && mousePosition.x <= 1406 && mousePosition.y >= 272 && mousePosition.y <= 365) {
            sprite_login.setTexture(texture8);
        } else if (mousePosition.x >= 519 && mousePosition.x <= 1407 && mousePosition.y >= 448 && mousePosition.y <= 545) {
            sprite_login.setTexture(texture9);
        } else {
            sprite_login.setTexture(texture6);
        }
}




void Display::render3()
{
    window.clear(sf::Color::Black);
    window.draw(sprite_login);

    if (select != 0) {
        window.draw(selectionRectangle);
    }

    font.loadFromFile("GUI/assets/minecraft_font.ttf");

    text_ip.setFont(font);
    text_ip.setString(ip_str);
    text_ip.setCharacterSize(31);
    text_ip.setFillColor(sf::Color::White);
    text_ip.setPosition(540, 300);
    window.draw(text_ip);

    text_port.setFont(font);
    text_port.setString(port_str);
    text_port.setCharacterSize(31);
    text_port.setFillColor(sf::Color::White);
    text_port.setPosition(540, 480);
    window.draw(text_port);

    text_failed.setFont(font);
    text_failed.setString("Connection to server failed");
    text_failed.setCharacterSize(47);
    text_failed.setFillColor(sf::Color::Red);
    text_failed.setPosition(565, 850);
    if (failed_connection == 1) {
        window.draw(text_failed);
    }

    text_failed.setFont(font);
    text_failed.setString(failed_str);
    text_failed.setCharacterSize(35);
    text_failed.setFillColor(sf::Color::Red);
    text_failed.setPosition(540, 620);


    window.display();
}


void Display::server_login()
{
    while (window.isOpen()) {
        handleEvents3();
        update3();
        render3();
    }
}