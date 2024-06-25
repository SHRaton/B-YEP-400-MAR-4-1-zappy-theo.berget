/*
** EPITECH PROJECT, 2024
** B-YEP-400-MAR-4-1-zappy-theo.berget
** File description:
** client_handling
*/

#include "../include/Core.hpp"

void Core::welcome()
{
    int num1;
    int num2;
    // Wait for WELCOME
    receive_from_server();
    if (std::string(buffer) != "WELCOME\n") {
        std::cout << "Not received \"WELCOME\\n\"";
        exit (56);
    }
    // Send TEAM-NAME (random because it's just for IA)
    send_to_server("IamTheGUI\n");
    // Wait for MAP_SIZE
    strcpy(buffer, "");
    receive_from_server();
    if (buffer == "") {
        std::cout << "Nothing received";
        exit (56);
    }
    std::istringstream iss(buffer);
    std::string str1;
    std::string str2;
    std::getline(iss, str1, ' ');
    std::getline(iss, str2, ' ');
    num1 = std::stoi(str1);
    num2 = std::stoi(str2);
    set_map_size(num1, num2);
}

void Core::client_loop()
{
    FD_ZERO(&fd_client);
    FD_SET(client_socket, &fd_client);
    FD_SET(0, &fd_client);
    struct timeval tv;
    welcome();
    map = generate_map(width, height);
    menuMusic.stop();
    menuGame.play();
    while (window.isOpen()) {
        usleep(10000);
        fd_user = fd_client;
        tv.tv_sec = 0;
        tv.tv_usec = 10000;
        int retval = select(client_socket + 1, &fd_user, NULL, NULL, &tv);
        if (retval == -1) {
            perror("select()");
            exit(84);
        } else if (retval > 0) {
            if (FD_ISSET(client_socket, &fd_user)) {
                receive_from_server();
                //std::cout << "(" << buffer << ")\n";
            }
            if (FD_ISSET(0, &fd_user)) {
                if (fgets(buff, sizeof(buff), stdin) != NULL) {
                    send_to_server(buff);
                }
            }
        }
        handleEvents4();
        update4();
        commands();
        render4();
    }
}

void Core::receive_from_server()
{
    std::string new_data;
    ssize_t bytes_rcvd;
    bytes_rcvd = read(client_socket, buffer, sizeof(buffer) - 1);
    if (bytes_rcvd <= 0) {
        if (bytes_rcvd == 0) {
            printf("Deconnexion du serveur.\n");
        } else {
            perror("Erreur lors de la lecture depuis le serveur");
        }
        exit(84);
    } else {
        buffer[bytes_rcvd] = '\0';
        sbuffer = std::string(buffer);
        vbuffer = str_to_word_array(sbuffer);
        std::cout << "\033[42m[RECEIVED]\033[0m --> " << sbuffer;
        std::ofstream file("./LOG/gui.log", std::ios::out | std::ios::app);
        if (!file.is_open()) {
            return;
        }
        file << "[RECEIVED] --> (\"" << sbuffer << "\")" << std::endl;
        file.close();
    }
}

void Core::send_to_server(std::string command)
{
    std::cout << "\033[43m[SENT]\033[0m --> " << command;
    send(client_socket, command.c_str(), strlen(command.c_str()), 0);
    std::ofstream file("./LOG/gui.log", std::ios::out | std::ios::app);
    if (!file.is_open()) {
        return;
    }
    if (command[command.size() - 1] == '\n') {
        command.pop_back();
    }
    file << "[SENT] --> (\"" << command << "\")" << std::endl;
    file.close();
}

int Core::init_socket_client()
{
    int cvd;

    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    sockaddrIn.sin_family = AF_INET;
    sockaddrIn.sin_addr.s_addr = inet_addr(ip_str.c_str());
    sockaddrIn.sin_port = htons(atoi(port_str.c_str()));
    cvd = connect(client_socket,
    (struct sockaddr *) &sockaddrIn, sizeof(sockaddrIn));
    if (cvd < 0) {
        return (9);
    }
    client_loop();
    return (0);
}
