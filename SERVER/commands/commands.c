/*
** EPITECH PROJECT, 2024
** B-YEP-400-MAR-4-1-zappy-alexandre.vittenet
** File description:
** commands
*/

#include "../include/my.h"

// Toutes les commandes du protocole AI
void commands_ai(server_t *s)
{
    forward(s);
    look(s);
    left(s);
    right(s);
    take(s);
    incantation(s);
}

// Toutes les commandes du protocole GUI
void commands_gui(server_t *s)
{
    infos(s);
    ppo(s);
    mct(s);
    pin(s);
    plv(s);
    bct(s);
    ebo(s);
    edi(s);
    enw(s);
    msz(s);
    pbc(s);
    pdr(s);
    pex(s);
    pfk(s);
    pgt(s);
    pic(s);
    pie(s);
    sbp(s);
    seg(s);
    sgt(s);
    smg(s);
    sst(s);
    suc(s);
    tna(s);
}

// Fonction qui gère les commandes recu par le serveur et si la commande
// n'existe pas renvoie "Wrong command" a l'utilisateur qui a fait la requete
void commands(server_t *s)
{
    commands_ai(s);
    commands_gui(s);
    if (s->server_data->isCommand == 0) {
        send(s->server_net->current->socket, "Wrong command\n", 16, 0);
        print_send_to_client(s, "Wrong command");
    }
    s->server_data->isCommand = 0;
}
