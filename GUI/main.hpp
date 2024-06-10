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
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

class Display {
public:
    Display();
    void Menu();
    void server_menu();
    void server_login();
    void change_ip_port(char *ip, char *port);

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
    void render4();
    void update4();
    void handleEvents4();
    void handleMouseClick(const sf::Vector2i& mousePosition);
    void handleMouseClick2(const sf::Vector2i& mousePosition);
    void handleMouseClick3(const sf::Vector2i& mousePosition);
    void handleKeyboard(sf::Event::KeyEvent key);
    int init_socket_client();
    std::vector<std::string> generate_map(int x, int y);
    void get_map_size();
    void receive_from_server();
    void send_to_server(std::string command);
    void client_loop();

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
    sf::Texture texture10;

    sf::RectangleShape selectionRectangle;

    sf::Sprite sprite_menu;
    sf::Sprite sprite_server;
    sf::Sprite sprite_login;
    sf::Sprite sprite_water;


    sf::Music menuMusic;
    sf::SoundBuffer soundBuffer;
    sf::Sound soundButton;


    sf::Text text_ip;
    sf::Text text_port;
    sf::Text text_failed;


    sf::Font font;

    std::string ip_str;
    std::string port_str;
    std::string failed_str;
    bool textEditing = false;
    std::string userInput;


    int select_button;

    int client_socket;
    struct sockaddr_in sockaddrIn;
    char buffer[1024];
    char *line;
    char *uuid_s;
    char *name;
    int isLogin;
    fd_set fd_client;
    fd_set fd_user;
    size_t line_size;

    int failed_connection;

    std::vector<std::string> map;
    int width;
    int height;

    sf::Texture textureHTAG;
    sf::Texture textureA;
    sf::Texture textureB;
    sf::Texture textureC;
    sf::Texture textureD;
    sf::Texture textureUP;
    sf::Texture textureDOWN;
    sf::Texture textureRIGHT;
    sf::Texture textureLEFT;

    sf::Sprite sprite_HTAG;
    sf::Sprite sprite_A;
    sf::Sprite sprite_B;
    sf::Sprite sprite_C;
    sf::Sprite sprite_D;
    sf::Sprite sprite_UP;
    sf::Sprite sprite_DOWN;
    sf::Sprite sprite_RIGHT;
    sf::Sprite sprite_LEFT;

};

#endif // MAIN_HPP
