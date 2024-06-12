##tout pour lucas(comme tout les ans)
##long

from connect import Client
import sys
import time

###################################################################################################

class AIPlayer:
    def __init__(self):
        self.teamName = False
        self.machine = False
        self.port = False
        self.AI = False
        self.client = None
        self.tour = 1
        self.pos = ""
        self.posX = 0
        self.posY = 0
        self.tile = 0

        self.food = 0
        self.linemate = 1
        self.deraumere = 2
        self.sibur = 3
        self.mendiane = 4
        self.phiras = 5
        self.thystame = 6
        self.player = 7

        self.best_item = None
        self.best_tile = 0
        self.look_ret = ""

###################################################################################################

    def send_message(self, message):
        self.client.send_message(message + "\n")

###################################################################################################

    def receive_message(self):
        return self.client.receive_message()

###################################################################################################

    def check_reply(self, tile, rep):
        if rep == "ok\n":
            return
        else:
            self.get_to_tile(self, tile)

###################################################################################################

    def get_to_tile(self, tile):
        if tile == 0:
            self.send_message("allready on tile")
            rep = self.receive_message()
            self.check_reply(self, tile, rep)
            return
        if tile == 1:
            self.send_message("Forward")
            self.send_message("Left")
            self.send_message("Take object")
            rep = self.receive_message()
            self.check_reply(self, tile, rep)
            return
        if tile == 2:
            self.send_message("Forward")
            rep = self.receive_message()
            self.check_reply(self, tile, rep)
            return
        if tile == 3:
            self.send_message("Forward")
            self.send_message("Right")
            rep = self.receive_message()
            self.check_reply(self, tile, rep)
            return
        if tile == 4:
            self.send_message("Forward")
            self.send_message("Forward")
            self.send_message("Left")
            self.send_message("Left")
            rep = self.receive_message()
            self.check_reply(self, tile, rep)
            return
        if tile == 5:
            self.send_message("Forward")
            self.send_message("Forward")
            self.send_message("Left")
            rep = self.receive_message()
            self.check_reply(self, tile, rep)
            return
        if tile == 6:
            self.send_message("Forward")
            self.send_message("Forward")
            rep = self.receive_message()
            self.check_reply(self, tile, rep)
            return
        if tile == 7:
            self.send_message("Forward")
            self.send_message("Forward")
            self.send_message("Right")
            rep = self.receive_message()
            self.check_reply(self, tile, rep)
            return
        if tile == 8:
            self.send_message("Forward")
            self.send_message("Forward")
            self.send_message("Right")
            self.send_message("Right")
            rep = self.receive_message()
            self.check_reply(self, tile, rep)
            return
        if tile == 9:
            self.send_message("Forward")
            self.send_message("Forward")
            self.send_message("Forward")
            self.send_message("Left")
            self.send_message("Left")
            self.send_message("Left")
            rep = self.receive_message()
            self.check_reply(self, tile, rep)
            return
        if tile == 10:
            self.send_message("Forward")
            self.send_message("Forward")
            self.send_message("Forward")
            self.send_message("Left")
            self.send_message("Left")
            rep = self.receive_message()
            self.check_reply(self, tile, rep)
            return
        if tile == 11:
            self.send_message("Forward")
            self.send_message("Forward")
            self.send_message("Forward")
            self.send_message("Left")
            rep = self.receive_message()
            self.check_reply(self, tile, rep)
            return
        if tile == 12:
            self.send_message("Forward")
            self.send_message("Forward")
            self.send_message("Forward")
            rep = self.receive_message()
            self.check_reply(self, tile, rep)
            return
        if tile == 13:
            self.send_message("Forward")
            self.send_message("Forward")
            self.send_message("Forward")
            self.send_message("Right")
            rep = self.receive_message()
            self.check_reply(self, tile, rep)
            return
        if tile == 14:
            self.send_message("Forward")
            self.send_message("Forward")
            self.send_message("Forward")
            self.send_message("Right")
            self.send_message("Right")
            rep = self.receive_message()
            self.check_reply(self, tile, rep)
            return
        if tile == 15:
            self.send_message("Forward")
            self.send_message("Forward")
            self.send_message("Forward")
            self.send_message("Right")
            self.send_message("Right")
            self.send_message("Right")
            rep = self.receive_message()
            self.check_reply(self, tile, rep)
            return

###################################################################################################

    def link_item_to_tile(self):
        item_list = self.ret_look.split(',')
        best_option_index = item_list.index(self.best_item)
        self.get_to_tile (self, best_option_index)

###################################################################################################

    def get_best_option(self, list_items_on_tile):
        max_value = 0
        best_option = None
        for item in list_items_on_tile:
            if item == "food":
                value = self.food
            elif item == "linemate":
                value = self.linemate
            elif item == "deraumere":
                value = self.deraumere
            elif item == "sibur":
                value = self.sibur
            elif item == "mendiane":
                value = self.mendiane
            elif item == "phiras":
                value = self.phiras
            elif item == "thystame":
                value = self.thystame
            elif item == "player":
                value = self.player
            if value > max_value:
                max_value = value
                best_option = item
        self.best_item = best_option
        self.link_item_to_tile(self)

###################################################################################################

    def select_tile(self, look_ret):
        list_items_on_tile = []
        tile_info = look_ret.split(',')
        for info in tile_info:
            if info.strip() == "food":
                list_items_on_tile.append(info.strip())
            elif info.strip() == "linemate":
                list_items_on_tile.append(info.strip())
            elif info.strip() == "deraumere":
                list_items_on_tile.append(info.strip())
            elif info.strip() == "sibur":
                list_items_on_tile.append(info.strip())
            elif info.strip() == "mendiane":
                list_items_on_tile.append(info.strip())
            elif info.strip() == "phiras":
                list_items_on_tile.append(info.strip())
            elif info.strip() == "thystame":
                list_items_on_tile.append(info.strip())
            elif info.strip() == "player":
                list_items_on_tile.append(info.strip())
        self.get_best_option(list_items_on_tile)

###################################################################################################

    def ai(self):
        while self.AI == False:
            time.sleep(self.tour)
            self.send_message("Look")
            look_ret = self.receive_message()
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
