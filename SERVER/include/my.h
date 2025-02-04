/*
** EPITECH PROJECT, 2024
** B-YEP-400-MAR-4-1-zappy-alexandre.vittenet
** File description:
** my
*/

#pragma once

#include "struct.h"

#define DEBUG 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <uuid/uuid.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <signal.h>
#include <math.h>
#include <signal.h>



//////////////////////////////////////////////
/* Déclarations des fonctions de SERVER/src */
//////////////////////////////////////////////

// -------- print.c -------- //
void print_usage(void);
void print_names(arg_t *arg);
void print_args(arg_t *arg);
void print_connect(sockaddr_in_t client_addr);
// ------------------------ //

// -------- parsing.c -------- //
void get_pos(char **av, int *flag_pos, int z);
int *recup_flag_pos(int ac, char **av);
int error_handling(int ac, char **av, arg_t *arg, int *flag_pos);
int flags_valid(int ac, char **av, arg_t *arg);
int parsing_argument(int ac, char **av, arg_t *arg);
// -------------------------- //

// -------- server.c -------- //
void start_server(arg_t *arg);
// -------------------------- //

// -------- chained_list_print.c -------- //
void print_clients(client_t *head);
void print_remove(client_t *current);
// -------------------------------------- //

// -------- chained_list.c -------- //
client_t *add_client(client_t *head, int new_s, sockaddr_in_t c, server_t *s);
client_t *remove_client2(client_t *current, client_t *prev, client_t *head);
client_t *remove_client(client_t *head, int socket_to_remove);
void free_clients(client_t *head);
// -------------------------------- //

// -------- init.c -------- //
void apply(server_t *s, arg_t *arg);
void re_use_port(server_t *s);
void init_socket(server_t *s);
// ------------------------ //


// -------- handle_connexion_with_fd.c -------- //
void set_the_fd(server_t *s);
void select_fd(server_t *s);
void accept_connexion(server_t *s);
void recup_input_from_client(server_t *s);
void handle_client(server_t *s);
// -------------------------------------------- //

// -------- send.c -------- //
void send_all_clients(client_t *head, char *msg, client_t *current);
void send_and_print(server_t *s, char *str, int socket);
// ------------------------ //

// -------- fonction.c -------- //
int is_contain(char *str, char cara);
char **str_to_word_array(char *str, char *tok);
char *reverse(char *str);
char *int_to_str(int num);
char *removed_quote(char *str);
// ---------------------------- //

// -------- fonction2.c -------- //
void print_strstr(char **str);
char *remove_cara(char *str, char c);
// ----------------------------- //

// -------- send_infos_to_new_client.c -------- //
void send_infos_to_new_client(server_t *s);
// -------------------------------------------- //

// -------- update.c -------- //
int update_nb_client(server_t *s, char *team_name, int add);
// -------------------------- //

// -------- queue.c -------- //
void enqueue(queue_t *q, char *command);
char *dequeue(queue_t *q);
void print_commands(queue_t *q);
void process_commands(server_t *s);
// ------------------------- //


// -------- free_server.c -------- //
void free_server(server_t *s);
// ------------------------------- //

///////////////////////////////////////////////////
/* Déclarations des fonctions de SERVER/commands */
///////////////////////////////////////////////////


// -------- commands_print.c --------- //
void print_received_from_client_head(server_t *s, char *str);
void print_received_from_client(server_t *s, char *str);
void print_send_to_client_head(server_t *s, char *str);
void print_send_to_client(server_t *s, char *str);
// ----------------------------------- //

// -------- commands.c --------- //
void commands(server_t *s);
// ----------------------------- //


///////////////////////////////////////////////////////////////
/* Déclarations des fonctions de SERVER/commands/commands_AI */
///////////////////////////////////////////////////////////////


void forward(server_t *s);
void incantation(server_t *s);
void left(server_t *s);
void look(server_t *s);
void right(server_t *s);
void take(server_t *s);


////////////////////////////////////////////////////////////////
/* Déclarations des fonctions de SERVER/commands/commands_GUI */
////////////////////////////////////////////////////////////////


void bct(server_t *s);
void ebo(server_t *s);
void edi(server_t *s);
void enw(server_t *s);
void infos(server_t *s);
void mct(server_t *s);
void msz(server_t *s);
void pbc(server_t *s);
void pdr(server_t *s);
void pex(server_t *s);
void pfk(server_t *s);
void pgt(server_t *s);
void pic(server_t *s);
void pie(server_t *s);
void pin(server_t *s);
void plv(server_t *s);
void pnw(server_t *s);
void ppo(server_t *s);
void sbp(server_t *s);
void seg(server_t *s);
void sgt(server_t *s);
void smg(server_t *s);
void sst(server_t *s);
void suc(server_t *s);
void tna(server_t *s);
