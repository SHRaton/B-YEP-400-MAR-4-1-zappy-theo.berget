#!/usr/bin/env python3
#coding: utf-8

import socket
import sys

class Client:
    def __init__(self, server_host, server_port):
        self.server_host = server_host
        self.server_port = server_port
        self.socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    def __del__(self):
        try:
            self.socket.close()
        except OSError:
            sys.exit("Connexion fermée")

    def connect(self):
        try:
            self.socket.connect((self.server_host, self.server_port))
        except ConnectionRefusedError:
            sys.exit("Connexion refusée")

    def send_message(self, message):
        try:
            self.socket.sendall(message.encode())
        except ConnectionResetError:
            sys.exit("La connexion avec le serveur a été interrompue")

    def receive_message(self):
        try:
            message = self.socket.recv(1024)
            return message.decode()
        except ConnectionResetError:
            sys.exit("La connexion avec le serveur a été interrompue")
            return None

    def close(self):
        try:
            self.socket.close()
        except OSError:
            sys.exit("Connexion fermée")

