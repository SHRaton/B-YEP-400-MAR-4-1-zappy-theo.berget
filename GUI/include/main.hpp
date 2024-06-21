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
#include <string>
#include <sstream>
#include <utility>

class ressources {

    public :
    int food;
    int coal;
    int iron;
    int gold;
    int diamond;
    int emerald;
    int netherite;

    sf::Text nb_food;
    sf::Text nb_coal;
    sf::Text nb_iron;
    sf::Text nb_gold;
    sf::Text nb_diamond;
    sf::Text nb_emerald;
    sf::Text nb_netherite;

     ressources(int food = 0, int coal = 0, int iron = 0, int gold = 0, int diamond = 0, int emerald = 0, int netherite = 0)
        : food(food), coal(coal), iron(iron), gold(gold), diamond(diamond), emerald(emerald), netherite(netherite) {}
};

class Info_Player {
    public :
        Info_Player() = default;
        ~Info_Player() = default;
        int player_number;
        int pos_x;
        int pos_y;
        int orientation;
        int animation;
        int level;
        std::string team_name;
        ressources inventory;
};

class Display {
public:
    Display();
    void Menu();
    void server_menu();
    void server_login();
    void change_ip_port(std::string ip, std::string port);

private:
    std::vector<std::vector<ressources>> ressources_grid;
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
    void set_map_size(int x, int y);
    void receive_from_server();
    void send_to_server(std::string command);
    void client_loop();
    void welcome();
    std::vector<std::string> str_to_word_array(std::string s);
    void commands();
    void pnw();
    void pdi();
    void ppo();
    void mct();
    void pin();

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

    sf::Music menuGame;

    sf::SoundBuffer soundBuffer;
    sf::Sound soundButton;

    sf::SoundBuffer soundBuffer_zoom;
    sf::Sound sound_zoom;

    sf::SoundBuffer soundBuffer_dezoom;
    sf::Sound sound_dezoom;


    sf::Text text_ip;
    sf::Text text_port;
    sf::Text text_failed;
    sf::Text text_level;
    sf::Text text_team_name;


    sf::Font font;

    std::string ip_str;
    std::string port_str;
    std::string failed_str;
    std::string userInput;


    int select_button;

    int client_socket;
    struct sockaddr_in sockaddrIn;
    char buffer[9999];
    std::string sbuffer;
    std::vector<std::string> vbuffer;
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

    sf::Sprite sprite_steve;
    sf::Texture textureSteve;

    sf::Sprite sprite_day;
    sf::Sprite sprite_night;
    sf::Clock clock;
    bool isDay;
    bool isSunset;
    bool isNight;
    sf::Time timeInterval;
    sf::Sprite sprite_sunset;;

    sf::Texture textureDay;
    sf::Texture textureNight;
    sf::Texture textureSunset;

    char buff[256];

    // ID (number) des joueurs connectés
    Info_Player info_player;

    // Position du joueur
    std::vector<Info_Player> info_players;
    std::vector<Info_Player> info_players_brut;

    //Position all ressources
    //std::vector<std::vector<ressources>> map;


    sf::Clock clock_pos;
    sf::Clock clock_mct;
    sf::Clock clock_pin;

    int surplu_x;
    int surplu_y;

    sf::Sprite sprite_food;
    sf::Sprite sprite_coal;
    sf::Sprite sprite_iron;
    sf::Sprite sprite_gold;
    sf::Sprite sprite_diamond;
    sf::Sprite sprite_emerald;
    sf::Sprite sprite_netherite;

    sf::Texture texture_food;
    sf::Texture texture_coal;
    sf::Texture texture_iron;
    sf::Texture texture_gold;
    sf::Texture texture_diamond;
    sf::Texture texture_emerald;
    sf::Texture texture_netherite;


    sf::Sprite sprite_player_inventory;
    sf::Texture texture_player_inventory;

    sf::Sprite sprite_case_inventory;
    sf::Texture texture_case_inventory;

    int animation;
    void handleClick(int mouseX, int mouseY);


    sf::Text resourceText;
    ressources selectedResources;

    double ratio;

    sf::SoundBuffer soundBuffer_zombie;
    sf::Sound sound_zombie;

    void showPlayerResources();
    ressources show_inv;
    int indx;
};

#endif // MAIN_HPP
