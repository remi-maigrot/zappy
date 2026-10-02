##
## EPITECH PROJECT, 2023
## AI
## File description:
## request
##

import ai.src.parser as parser
import time

class Request:
    '''Class to send request to server'''
    def __init__(self) -> None:
        self.inventory: dict = {}
        self.team_inventory: dict = {"food": 0, "linemate": 0, "deraumere": 0,"sibur": 0, "mendiane": 0, "phiras": 0, "thystame": 0}
        self.broad_cast_history: list = []
        self.broad_cast_waiting: list = []
        self.vision: list = []
        self.level = 1
        self.cases = {
            "connect": self.ask_connect_number,
            "fork": self.ask_to_fork,
        }

    def ask_connect_number(self, client_socket) -> int:
        '''Ask number of unused connection'''
        client_socket.send(b"Connect_nbr\n")
        data: str = client_socket.recv(1024)
        data_str = data.decode("utf-8")

        return int(data_str)

    def ask_to_fork(self, client_socket) -> str:
        '''Ask to fork'''
        client_socket.send(b"Fork\n")
        data: str = client_socket.recv(1024)
        data_str = data.decode("utf-8")

        return data_str

    def handle_sending_request(self, client_socket, request: list) -> bool:
        '''Handle sending request'''
        max_command = 10
        total_requests = len(request)
        current_index = 0

        print(f"Voici la liste de request, {request}")
        while current_index < total_requests:
            batch = request[current_index:current_index + max_command]
            responses = []

            for req in batch:
                if isinstance(req, list):  # Vérifie si req est un tuple
                    client_socket.send(req[0].encode() + req[1].encode() + b"\n")
                else:
                    client_socket.send(req.encode() + b"\n")

                data: str = client_socket.recv(1024)
                data_str = data.decode("utf-8")

                #if "message" in data_str:
                while "message" in data_str:
                    self.broad_cast_history.append(data_str)
                    data: str = client_socket.recv(1024)
                    data_str = data.decode("utf-8")

                if data_str == "Elevation underway\n":
                    temp: str = client_socket.recv(1024)
                    temp_str = temp.decode("utf-8")
                    responses.append([data_str, temp_str])

                    print(f'La fonction envoyé {req}, réponse :{data_str}')
                    continue

                print(f'La fonction envoyé {req}, réponse :{data_str}')
                responses.append(data_str)


            for response in responses: # Ici on va gérer l'eventuel broadcast
                if batch[0] == "Incantation":
                    temp = response[1].split(" ")
                    print(temp)
                    try:
                        num = int(temp[2])
                    except ValueError:
                        exit(84)
                    if num > self.level:
                        self.level += 1
                        print("On level UPPPPP")
                elif isinstance(batch[0], list):
                    if batch[0][0] == "Take " and response == "ok\n" and batch[0][1] != "food":
                        self.broad_cast_waiting.append(["Broadcast ", "ADD " + batch[0][1]])
                        batch.pop(0)
                        responses.pop(0)
                        continue
                elif response == "ok\n" or response == "ko":
                    print(f"Commande {batch[0]}: {response}")
                    batch.pop(0)
                    responses.pop(0)

                elif batch[0] == "Look" or batch[0] == "Inventory":
                    if batch[0] == "Look":
                        self.vision = parser.parse_vision(response)
                    else:
                        self.inventory = parser.parse_inventory(response)
                    batch.pop(0)
                    responses.pop(0)
                    continue

            current_index += max_command
            time.sleep(1)

    def uncapsulate_request(self, tuple_of_request: list) -> list:
        '''Receive a list of tuple and send back a list'''
        command_list = []

        if len(tuple_of_request) == 0:
            return command_list

        for command, count in tuple_of_request:
            command_list.extend([command] * count)

        return command_list
