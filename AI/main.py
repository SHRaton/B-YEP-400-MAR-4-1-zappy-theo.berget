## ZAPPY
## AI

from connect import Client
import sys

###################################################################################################
class self:
    def __init__(self):
        self.teamName = False
        self.machine = False
        self.port = False


def joinGame(self):
    self.client = Client(self.machine, self.port)
    self.client.connect()
    receive = self.client.receive_message()
    print(receive)
    send_message(self, self.teamName)
    if receive == "WELCOME\n":
        self.client.send_message(self.teamName + "\n")
    receive = self.client.receive_message()

def print_help():
    print('USAGE: ./zappy_ai -p port -n name -h machine')
    print('\tport is the port number')
    print('\tname is the name of the team')
    print('\tmachine is the name of the machine; localhost by default')

def send_message(self, message):
    self.client.send_message(message + "\n")

def receive_message(self):
    return self.client.receive_message()

def can_fork(self):
    send_message(self, "Look")
    receive = receive_message(self)
    if receive == "ko\n":
        return False
    return True

def main():
    if len(sys.argv) != 7:
        print_help()
        return
    if sys.argv[1] != '-p' or sys.argv[3] != '-n' or sys.argv[5] != '-h':
        print_help()
        return
    self.port = int(sys.argv[2])
    self.teamName = sys.argv[4]
    self.machine = sys.argv[6]
    joinGame(self)

if __name__ == '__main__':
    main()