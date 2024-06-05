## ZAPPY
## AI

import os
import sys
import AI as ai

###################################################################################################

def print_help():
    print('USAGE: ./zappy_ai -p port -n name -h machine')
    print('\tport is the port number')
    print('\tname is the name of the team')
    print('\tmachine is the name of the machine; localhost by default')

def main():
    if len(sys.argv) != 7:
        print_help()
        return
    if sys.argv[1] != '-p' or sys.argv[3] != '-n' or sys.argv[5] != '-h':
        print_help()
        return
    port = int(sys.argv[2])
    name = sys.argv[4]
    machine = sys.argv[6]
    ai.run(port, name, machine)