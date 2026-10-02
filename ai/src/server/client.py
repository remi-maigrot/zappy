##
## EPITECH PROJECT, 2023
## Zappy
## File description:
## client
##

import threading
import socket

from ai.src.server.request import Request
from math import nan

class ServerClient:
    '''Class for the client'''

    def __init__(self, port: int, team_name: str) -> None:
        self.port: int = port
        self.team_name: str = team_name
        self.host_name: str = "127.0.0.1"
        self.request = Request()
        self.client_socket = nan # type: ignore
        self.server_response = nan # type: ignore
        self.client_number: int = 0
        self.map_size = []

    def connect_to_server(self) -> None: # Init the connection to the server
        self.client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.client_socket.connect((self.host_name, self.port))
        data: str = self.client_socket.recv(1024)
        print(data.decode())

        self.send_team_name()
        data: str = self.client_socket.recv(1024)
        data_str: str = data.decode("utf-8")

        temp: list = data_str.split("\n")
        print(temp)
        self.client_number = int(temp[0])
        temp = temp[1].split(" ")
        self.map_size = [int(temp[0]), int(temp[1])]
        print(data.decode())

    def close_connection(self) -> None:
        self.client_socket.close()

    def send_team_name(self) -> None:
        self.team_name += "\n"
        self.client_socket.send(self.team_name.encode())

def connect_to_server(port: int, team_name: str) -> None:
    '''Connect to server'''
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client_socket.connect(("127.0.0.1", port))

    data: str = client_socket.recv(1024)
    print(data.decode())

    team_name += "\n"
    client_socket.send(team_name.encode())
    print(team_name)
    data: str = client_socket.recv(1024)
    print(data.decode())

    client_socket.close()