#!/usr/bin/env python3

##
## EPITECH PROJECT, 2023
## zappy
## File description:
## tratorian class (client)
##

from ai.src.server.client import ServerClient
from enum import Enum
from sys import exit

class State(Enum):
    '''Enum for the state of the algorithm'''

    START = -1
    FORK = 0
    LEVEL1 = 1
    LEVELS = 2
    SEARCH_FOOD = 3
    SEARCH_STONES = 4
    ELEVATION = 5

class Inventory:
    '''Class for the inventory by levels'''

    def __init__(self) -> None:
        self.level3: dict = { "food": 5, "linemate": 1, "deraumere": 1, "sibur": 1, "mendiane": 0, "phiras": 0, "thystame": 0}
        self.level4: dict = { "food": 5, "linemate": 2, "deraumere": 0, "sibur": 1, "mendiane": 0, "phiras": 2, "thystame": 0}
        self.level5: dict = { "food": 5, "linemate": 1, "deraumere": 1, "sibur": 2, "mendiane": 0, "phiras": 1, "thystame": 0}
        self.level6: dict = { "food": 5, "linemate": 1, "deraumere": 2, "sibur": 1, "mendiane": 3, "phiras": 0, "thystame": 0}
        self.level7: dict = { "food": 5, "linemate": 1, "deraumere": 2, "sibur": 3, "mendiane": 0, "phiras": 1, "thystame": 0}
        self.level8: dict = { "food": 5, "linemate": 2, "deraumere": 2, "sibur": 2, "mendiane": 2, "phiras": 2, "thystame": 1}
        self.levels: dict = { "food": 30, "linemate": 9, "deraumere": 8, "sibur": 10, "mendiane": 5, "phiras": 6, "thystame": 1}

class Trantorian:

    '''Class for the tratorian'''

    def __init__(self) -> None:
        self.team_name: str = ""
        self.level: int = 1
        self.life: float = 1260                              #! Needs to be divides by f
        self.text_send: list = []
        self.text_receive: list = []
        self.commands: list = []
        self.is_hungry: bool = False
        self.info = None
        self.state = State.START
        self.is_first: bool = False
        self.inventory = Inventory()

    def start_tratorian(self, client_info: list) -> None:
        '''Start the tratorian class and init client connection'''

        self.info = ServerClient(client_info[0], client_info[1])
        self.team_name = client_info[1]
        self.info.connect_to_server()
        self.loop()

    def is_first(self) -> bool:
        '''Check if the tratorian is the first one'''

        co_nb :int = self.info.request.ask_connect_number(self.info.client_socket)
        if self.info.client_number - co_nb == 1:
            return True
        else:
            return False

    def add_egg_client(self) -> None:
        '''If fisrt player, fork 5 eggs'''

        if self.is_first == True:
            print("IS_FIRST true sa mere")
            self.is_first = True
            for i in range(5):
                self.commands.append("Fork")
                self.commands.append("Forward")
                #self.info.request.ask_to_fork(self.info.client_socket)
                #self.info.request.ask_to_go_forward(self.info.client_socket)

    def preliminaries(self) -> None:
        '''All the repetitive function that happen before the main loop'''
        if len(self.info.request.broad_cast_history) > 0:
                self.handle_broadcast()
        else:
            print("NO BROADCAST")

        self.commands += self.info.request.broad_cast_waiting
        self.info.request.broad_cast_waiting = []
        if len(self.commands) > 0:
                self.info.request.handle_sending_request(self.info.client_socket, self.commands) # Send commands
        self.commands = [] # Reset commands

        self.info.request.handle_sending_request(self.info.client_socket, ["Look"])

        for element in self.info.request.vision[0]:
                responses = [self.commands.append(["Take ", key]) for key, value in self.info.request.vision[0].items() if key != 'player']

        self.info.request.handle_sending_request(self.info.client_socket, ["Inventory"])

    def loop(self) -> None:
        '''Main loop for the tratorian'''

        while True:
            self.preliminaries()
            # self.add_egg_client()
            if 'food' in self.info.request.inventory and self.info.request.inventory["food"] < 10:
                self.is_hungry = True
                self.find_item_location("food")
            else:
                self.is_hungry = False
                self.action()

    def action(self) -> None:
        '''Main action for the tratorian'''

        if self.level == 1:
            self.level_one()
        else:
            self.level_up()

    def find_item_location(self, object: str) -> None:
        '''Find the location of the item'''
        index: int = 0
        find = False

        print(f"On cherche {object}")

        for tile in self.info.request.vision:
            if object in tile and tile[object] >= 1: # Y'a un item sur la case
                path: list = self.find_path(index)
                if path != None:
                    path: list = self.info.request.uncapsulate_request(path)
                    self.commands += path
                find = True
                break
            else:
                index += 1
        if find == False:
            self.commands.append("Forward")

    def drop_item(self):
        '''Drop all the item except food'''

        print("Drop item")
        for item in self.info.request.inventory:
            if item != "food":
                for i in range(self.info.request.inventory[item]):
                    self.info.request.ask_to_set_object_dow(self.info.client_socket, item)

    def level_one(self) -> None:
        '''Level one action'''

        if 'linemate' in self.info.request.inventory and self.info.request.inventory["linemate"] >= 1:
            print("##############################################")
            print(f"L'inventaire avant l'elevation {self.info.request.inventory}")
            self.info.request.handle_sending_request(self.info.client_socket, [["Broadcast ", "ADD linemate"]])
            self.info.request.handle_sending_request(self.info.client_socket, [["Set ", "linemate"]])
            self.info.request.handle_sending_request(self.info.client_socket, ["Incantation"])

            if self.info.request.level == 2:
                self.level += 1
                self.info.request.handle_sending_request(self.info.client_socket, ["Look"])
                print(f"La vision niveau 2 {self.info.request.vision}")
                exit(0)
            else:
                print("Pas d'elevation")
        else: # Fonction classique pour passer level 1
            self.find_item_location("linemate")

    def level_up(self) -> None:
        '''Action to do for level up'''

    def find_best_way(self, index :int, tmp: int, forward: int) -> list[tuple[str, int]]:
        '''Find the best way to go to the tile'''

        instructions: list[tuple[str, int]] = []
        nb_forward_start: tuple[str, int] = ("Forward", forward)
        instructions.append(nb_forward_start)
        if tmp - index < 0:
            nb_right: tuple[str, int] = ("Right", 1)
            instructions.append(nb_right)
        if  tmp - index > 0:
            nb_left: tuple[str, int] = ("Left", 1)
            instructions.append(nb_left)
        nb_forward_end: tuple[str, int] = ("Forward", abs(tmp - index))
        instructions.append(nb_forward_end)
        return instructions

    def find_path(self, index: int) -> list[tuple[str, int]]:
        '''Find the path to the tile'''

        tmp: int = 0
        forward: int = 0

        if index >= 64:
            tmp = 72
            forward = 8
            return self.find_best_way(index, tmp, forward)
        if index >= 49:
            tmp = 56
            forward = 7
            return self.find_best_way(index, tmp, forward)
        if index >= 36:
            tmp = 42
            forward = 6
            return self.find_best_way(index, tmp, forward)
        if index >= 25:
            tmp = 30
            forward = 5
            return self.find_best_way(index, tmp, forward)
        if index >= 16:
            tmp = 20
            forward = 4
            return self.find_best_way(index, tmp, forward)
        if index >= 9:
            tmp = 12
            forward = 3
            return self.find_best_way(index, tmp, forward)
        if index >= 4:
            tmp = 6
            forward = 2
            return self.find_best_way(index, tmp, forward)
        if index >= 1:
            tmp = 2
            forward = 1
            return self.find_best_way(index, tmp, forward)

    def can_do_all_elevations(self) -> bool:
        '''Compare the team inventory and the levels inventory, return true is they have at least the same amount'''

        for item in self.info.request.team_inventory:
            if item != "food":
                if self.info.request.team_inventory[item] < self.info.request.level[self.inventory.levels][item]:
                    return False
        if self.info.request.inventory["food"] > self.info.request.level[self.inventory.levels]["food"]:
            return False
        return True

    def drop_items(self, item: str, nb: int) -> None:
        '''Drop the item'''

        for i in range(nb):
            self.info.request.ask_to_set_object_down(self.info.client_socket, item)

    def do_specific_elevation(self, level_to_go: str) -> None:
        '''Compare the team inventory and the levels inventory, return true is they have at least the same amount'''

        if self.is_first == True:
            for item in self.inventory.levels[level_to_go]:
                if item != "food":
                    self.drop_items(item, self.inventory.lvl[item])
            self.info.request.ask_to_incantation(self.info.client_socket)

    def handle_broadcast(self) -> None:
        '''Handle the broadcast'''

        print(f"Handle Broadcast")
        k: int = 0
        for message in self.info.request.broad_cast_history:
            k = message.split(" ")[1]
            print(f"Le k {k}")
            txt: str = message.split(",")
            print(f"Le txt {txt}")

            if txt[1].startswith(" ADD"):
                item = txt[1].split(" ")[2]
                item = item.replace("\n", "")
                self.info.request.team_inventory[item] += 1
                print(f"Le team inventory {self.info.request.team_inventory}")
            self.info.request.broad_cast_history.pop(0)
