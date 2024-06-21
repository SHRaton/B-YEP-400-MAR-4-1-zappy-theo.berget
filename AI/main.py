#!/usr/bin/env python3
#coding: utf-8
#j'ai tout coder dans un fichier je suis le plus gros fdp de france

import sys
import time
import socket

###################################################################################################

class Client:
    def __init__(self, server_host, server_port):
        self.server_host = server_host
        self.server_port = server_port
        self.socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

###################################################################################################

    def __del__(self):
        try:
            self.socket.close()
        except OSError:
            sys.exit("Connexion fermée")

###################################################################################################

    def connect(self):
        try:
            self.socket.connect((self.server_host, self.server_port))
        except ConnectionRefusedError:
            sys.exit("Connexion refusée")

###################################################################################################

    def send_message(self, message):
        try:
            self.socket.sendall(message.encode())
        except ConnectionResetError:
            sys.exit("La connexion avec le serveur a été interrompue")

###################################################################################################

    def receive_message(self):
        try:
            message = self.socket.recv(1024)
            return message.decode()
        except ConnectionResetError:
            sys.exit("La connexion avec le serveur a été interrompue")
            return None

###################################################################################################

    def close(self):
        try:
            self.socket.close()
        except OSError:
            sys.exit("Connexion fermée")

###################################################################################################

class AIPlayer:
    def __init__(self):
        self.teamName = False
        self.machine = False
        self.port = False
        self.AI = False
        self.client = None
        self.tour = 2
        self.wait_move = 1
        self.pos = ""
        self.posX = 0
        self.posY = 0
        self.tile = 0
        self.start = True

        self.food = 7
        self.linemate = 1
        self.deraumere = 2
        self.sibur = 3
        self.mendiane = 4
        self.phiras = 5
        self.thystame = 6
        self.player = 0

        self.have_food = 0
        self.have_linemate = 0
        self.have_deraumere = 0
        self.have_sibur = 0
        self.have_mendiane = 0
        self.have_phiras = 0
        self.have_thystame = 0
        self.have_player = 0

        self.nb_player = 0

        self.best_item = None
        self.best_take_item = None
        self.best_tile = 0
        self.look_ret = ""
        self.list_items_on_tile = []

        self.size_map = 0        
        self.org_list_items_on_tile = []
        self.level = 0


###################################################################################################

    def send_message(self, message):
        self.client.send_message(message + "\n")
        time.sleep(self.wait_move)

###################################################################################################

    def receive_message(self):
        return self.client.receive_message()

###################################################################################################

    def check_reply(self, tile, rep):
        if rep == "ok\n":
            return
        else:
            return
            self.get_to_tile(self, tile)

###################################################################################################

    def take_add_to_obj(self):
        take = "Take " + self.best_item
        return take

###################################################################################################

    def get_to_tile(self, tile):
        if tile == 0:
            self.send_message("Allready on tile")
            return
        if tile == 1:
            self.send_message("Forward")
            self.send_message("Left")
            self.send_message("Forward")
            self.send_message(self.take_add_to_obj())
            return
        if tile == 2:
            self.send_message("Forward")
            self.send_message(self.take_add_to_obj())
            rep = self.receive_message()
            return
        if tile == 3:
            self.send_message("Forward")
            self.send_message("Right")
            self.send_message("Forward")
            self.send_message(self.take_add_to_obj())
            rep = self.receive_message()
            return
        if tile == 4:
            self.send_message("Forward")
            self.send_message("Forward")
            self.send_message("Left")
            self.send_message("Forward")
            self.send_message("Forward")
            self.send_message(self.take_add_to_obj())
            rep = self.receive_message()
            return
        if tile == 5:
            self.send_message("Forward")
            self.send_message("Forward")
            self.send_message("Left")
            self.send_message("Forward")
            self.send_message(self.take_add_to_obj())
            rep = self.receive_message()
            return
        if tile == 6:
            self.send_message("Forward")
            self.send_message("Forward")
            self.send_message(self.take_add_to_obj())
            rep = self.receive_message()
            return
        if tile == 7:
            self.send_message("Forward")
            self.send_message("Forward")
            self.send_message("Right")
            self.send_message("Forward")
            self.send_message(self.take_add_to_obj())
            rep = self.receive_message()
            return
        if tile == 8:
            self.send_message("Forward")
            self.send_message("Forward")
            self.send_message("Right")
            self.send_message("Forward")
            self.send_message("Forward")
            self.send_message(self.take_add_to_obj())
            rep = self.receive_message()

            return
        if tile == 9:
            self.send_message("Forward")
            self.send_message("Forward")
            self.send_message("Forward")
            self.send_message("Left")
            self.send_message("Forward")
            self.send_message("Forward")
            self.send_message("Forward")
            self.send_message(self.take_add_to_obj())
            rep = self.receive_message()

            return
        if tile == 10:
            self.send_message("Forward")
            self.send_message("Forward")
            self.send_message("Forward")
            self.send_message("Left")
            self.send_message("Forward")
            self.send_message("Forward")
            self.send_message(self.take_add_to_obj())
            rep = self.receive_message()
            return
        if tile == 11:
            self.send_message("Forward")
            self.send_message("Forward")
            self.send_message("Forward")
            self.send_message("Left")
            self.send_message("Forward")
            self.send_message(self.take_add_to_obj())
            rep = self.receive_message()

            return
        if tile == 12:
            self.send_message("Forward")
            self.send_message("Forward")
            self.send_message("Forward")
            self.send_message(self.take_add_to_obj())
            rep = self.receive_message()

            return
        if tile == 13:
            self.send_message("Forward")
            self.send_message("Forward")
            self.send_message("Forward")
            self.send_message("Right")
            self.send_message("Forward")
            self.send_message(self.take_add_to_obj())
            rep = self.receive_message()

            return
        if tile == 14:
            self.send_message("Forward")
            self.send_message("Forward")
            self.send_message("Forward")
            self.send_message("Right")
            self.send_message("Forward")
            self.send_message("Forward")
            self.send_message(self.take_add_to_obj())
            rep = self.receive_message()

            return
        if tile == 15:
            self.send_message("Forward")
            self.send_message("Forward")
            self.send_message("Forward")
            self.send_message("Right")
            self.send_message("Forward")
            self.send_message("Forward")
            self.send_message("Forward")
            self.send_message(self.take_add_to_obj())
            rep = self.receive_message()

            return

###################################################################################################

    def link_item_to_tile(self):
        #print("link_item_to_tile")
        def cleaning(element):
            return element.strip('[] ')
        liste = [cleaning(element) for element in self.org_list_items_on_tile]
        best_option_index = liste.index(self.best_item)
        #print(best_option_index)
        self.get_to_tile(best_option_index)
        return

###################################################################################################

    def is_evolution(self):
        if (self.have_linemate >= 1 and self.level < 2):
            self.send_message("Evolution 2")
            self.level = 2
        if (self.nb_player >= 2 and self.have_deraumere >= 1 and self.have_linemate >= 1 and self.have_sibur >= 1 and self.have_phiras >= 2 and self.level < 3):
            self.send_message("Evolution 3")
            self.level = 3
        ##verifier les condition avec multi player (broadcast??)

###################################################################################################

    def get_level_one_ressources(self):
        if "linemate" in self.list_items_on_tile:
            self.best_item = "linemate"
            return
    ###################################################################################################

    def get_level_two_ressources(self):
        if "deraumere" in self.list_items_on_tile and self.have_linemate >= 1:
            self.best_item = "deraumere"
            return
        if "sibur" in self.list_items_on_tile and self.have_linemate >= 1 and self.have_deraumere >= 1:
            self.best_item = "sibur"
            return
        if "mendiane" in self.list_items_on_tile and self.have_linemate >= 1 and self.have_deraumere >= 1 and self.have_sibur >= 2:
            self.best_item = "mendiane"
            return
        if "phiras" in self.list_items_on_tile and self.have_linemate >= 1 and self.have_deraumere >= 1 and self.have_sibur >= 2 and self.have_mendiane >= 3:
            self.best_item = "phiras"
            return
        if "thystame" in self.list_items_on_tile and self.have_linemate >= 1 and self.have_deraumere >= 1 and self.have_sibur >= 2 and self.have_mendiane >= 3 and self.have_phiras >= 4:
            self.best_item = "thystame"
            return

###################################################################################################

    def get_best_option(self):
        max_value = -1
        value = 0
        best_option = None
        for item in self.list_items_on_tile:
            if item == "food":
                value = self.food
                self.have_food = self.have_food + 1
            elif item == "linemate":
                value = self.linemate
                self.have_linemate = self.have_linemate + 1
            elif item == "deraumere":
                value = self.deraumere
                self.have_deraumere = self.have_deraumere + 1
            elif item == "sibur":
                value = self.sibur
                self.have_sibur = self.have_sibur + 1
            elif item == "mendiane":
                value = self.mendiane
                self.have_mendiane = self.have_mendiane + 1
            elif item == "phiras":
                value = self.phiras
                self.have_phiras = self.have_phiras + 1
            elif item == "thystame":
                value = self.thystame
                self.have_thystame = self.have_thystame + 1
            elif item == "player":
                value = self.player
            if value > max_value:
                max_value = value
                best_option = item
        self.best_item = best_option
        if self.level == 0:
            self.get_level_one_ressources()
        elif self.level == 1:
            self.get_level_two_ressources()

        self.link_item_to_tile()
        return

###################################################################################################

    def select_tile(self, look_ret):
        
        list_items_on_tile = []
        tile_info = look_ret.split(',')
        #print(tile_info)
        parse = ""
        for info in tile_info:
            parse += info.strip() + " "
        list_items_on_tile = parse.split()

        ###################################################################################################

        def cleaning(element):
            return element.strip('[] ')

        ###################################################################################################

        liste = [cleaning(element) for element in list_items_on_tile]
        liste_sans_doublons = []
        elements_vus = set()
        for item in liste:
            if item not in elements_vus:
                liste_sans_doublons.append(item)
                elements_vus.add(item)
        self.list_items_on_tile = liste_sans_doublons
        self.org_list_items_on_tile = list_items_on_tile
        #print(liste_sans_doublons)
        #print(list_items_on_tile)
        self.get_best_option()
        return

#git@github.com:EpitechPromo2027/B-YEP-400-MAR-4-1-zappy-theo.berget.git
#en clair gg

###################################################################################################

    def ai(self):
        while self.AI == False:
            if self.start == True:
                nb_player = self.receive_message()
                if nb_player == '0':
                    self.AI = True
                time.sleep(self.tour)
                self.size_map =  self.receive_message()
                print("size map :")
                print(self.size_map)
                self.start = False
            self.is_evolution()
            self.send_message("Look")
            look_ret = self.receive_message()
            print("look return :")
            print(look_ret)
            self.look_ret = look_ret
            self.select_tile(look_ret)
            

###################################################################################################

    def join_game(self):
        self.client = Client(self.machine, self.port)
        self.client.connect()
        receive = self.client.receive_message()
        if receive == "WELCOME\n":
            self.client.send_message(self.teamName + "\n")
            self.ai()

###################################################################################################

def print_help():
    print('USAGE: ./zappy_ai -p port -n name -h machine')
    print('\tport is the port number')
    print('\tname is the name of the team')
    print('\tmachine is the name of the machine; localhost by default')

###################################################################################################

def main():
    if len(sys.argv) != 7:
        print_help()
        return

    if sys.argv[1] != '-p' or sys.argv[3] != '-n' or sys.argv[5] != '-h':
        print_help()
        return

    player = AIPlayer()
    player.port = int(sys.argv[2])
    player.teamName = sys.argv[4]
    player.machine = sys.argv[6]
    player.join_game()

if __name__ == '__main__':
    main()

###################################################################################################
