/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** main
*/

#ifndef MAIN_HPP
#define MAIN_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

class Display {
public:
    Display();
    void Menu();
    void server_menu();
    void server_login();

private:
    void loadAssets();
    void handleEvents();
    void update();
    void render();
    void render2();
    void update2();
    void handleEvents2();
    void render3();
    void update3();
    void handleEvents3();
    void handleMouseClick(const sf::Vector2i& mousePosition);
    void handleMouseClick2(const sf::Vector2i& mousePosition);
    void handleMouseClick3(const sf::Vector2i& mousePosition);
    void handleKeyboard(sf::Event::KeyEvent key);

    sf::RenderWindow window;
    sf::Texture texture1;
    sf::Texture texture2;
    sf::Texture texture3;
    sf::Texture texture4;
    sf::Texture texture5;
    sf::Texture texture6;
    sf::Texture texture7;
    sf::Texture texture8;
    sf::Texture texture9;
    sf::Sprite sprite_menu;
    sf::Sprite sprite_server;
    sf::Sprite sprite_login;
    sf::Music menuMusic;
    sf::SoundBuffer soundBuffer;
    sf::Sound soundButton;
    sf::Text text_ip;
    sf::Text text_port;
    sf::Font font;
    std::string ip_str;
    std::string port_str;

    bool textEditing = false;
    std::string userInput;
};

#endif // MAIN_HPP

